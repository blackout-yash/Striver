// 355. Design Twitter
// Link - https://leetcode.com/problems/design-twitter/



#define ppi pair<int, pair<int, int>>
class Twitter {
public:
	int cnt;
	map <int, set <int>> m;
	priority_queue <ppi> pq;

	Twitter() {
		cnt = 0;
	}

	void postTweet(int userId, int tweetId) {
		pq.push({cnt, {userId, tweetId}});
		cnt++;
	}

	vector<int> getNewsFeed(int userId) {
		vector <int> ans;
		vector <ppi> temp;
		while (!pq.empty()) {
			temp.push_back(pq.top());
			int currUserId = pq.top().second.first,
			    tweetId = pq.top().second.second;
			pq.pop();

			if (currUserId == userId || m[userId].find(currUserId) != m[userId].end()) {
				ans.push_back(tweetId);
			}
			if (ans.size() == 10) break;
		}
		for (auto x : temp) pq.push(x);
		return ans;
	}

	void follow(int followerId, int followeeId) {
		m[followerId].insert(followeeId);
	}

	void unfollow(int followerId, int followeeId) {
		m[followerId].erase(followeeId);
	}
};