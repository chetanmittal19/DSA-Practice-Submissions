class Twitter {
    // The Code Mate: https://youtu.be/6je5osXSwOU
    private static int timeStamp = 0;
    private Map<Integer, User> userMap;

    private class Tweet {
        public int id;
        public int time;
        public Tweet next;

        public Tweet(int id) {
            this.id = id;
            time = timeStamp++;
            next = null;
        }
    }

    public class User {
        public int id;
        public Set<Integer> followed;
        public Tweet tweet_head; // tweet head pointer

        public User(int id) {
            this.id = id;
            followed = new HashSet<>();
            follow(id); // first follow itself
            tweet_head = null;
        }

        public void follow(int id) {
            followed.add(id);
        }

        public void unfollow(int id) {
            followed.remove(id);
        }

        // everytime user post a new tweet, add it to the head of tweet list
        public void post(int id) {
            Tweet t = new Tweet(id);
            t.next = tweet_head;
            tweet_head = t;
        }
    }

    

    public Twitter() {
        // write your code here
        userMap = new HashMap<>();
    }
    
    public void postTweet(int userId, int tweetId) {
        // write your code here
        if(!userMap.containsKey(userId)) {
            User u = new User(userId);
            userMap.put(userId, u);
        }
        userMap.get(userId).post(tweetId);
    }
    
    public List<Integer> getNewsFeed(int userId) {
        // write your code here
        List<Integer> res = new LinkedList<>();
        if(!userMap.containsKey(userId)) return res;
        Set<Integer> users = userMap.get(userId).followed; //max heap
        PriorityQueue<Tweet> pq = new PriorityQueue<>(users.size(), (a,b)->(b.time-a.time));

        for(int user: users) {
            Tweet t = userMap.get(user).tweet_head;
            if(t!=null) pq.add(t); // don't add null in heap
        }

        int n=0;
        while(!pq.isEmpty() && n<10) {
            Tweet t = pq.poll();
            res.add(t.id);
            n++;
            if(t.next!=null) pq.add(t.next);
        }
        return res;
    }
    
    public void follow(int followerId, int followeeId) {
        // write your code here
        if(!userMap.containsKey(followerId)) {
            User u = new User(followerId);
            userMap.put(followerId, u);
        }
        if(!userMap.containsKey(followeeId)) {
            User u = new User(followeeId);
            userMap.put(followeeId, u);
        }
        userMap.get(followerId).follow(followeeId);
    }
    
    public void unfollow(int followerId, int followeeId) {
        // write your code here
        if(!userMap.containsKey(followerId) || followerId == followeeId) return;
        userMap.get(followerId).unfollow(followeeId);
    }
}

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * List<Integer> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */