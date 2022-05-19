#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include<vector>

//用户可以发送微博，关注/取关其他用户，查看用户的关注数、粉丝 数、微博数，查看最近的微博

using namespace std;

//所有输入中的id保证为int类型的正整数，微博id保证不重复 可以认为微博发布的时间与post命令的先后顺序一致
//提示：优先实现发布、关注等基本功能以及查看关注数、粉丝数、微博数，拿到部分用例分数

//互相关注==好友圈
class Weibo {
public:
	int userId;
	int weiboId;
	int type; //0代表仅自己可见，1代表好友圈可见，2代表粉丝可见 

	Weibo() {};
	Weibo(int uid, int wid, int tp) {
		userId = uid;
		weiboId = wid;
		type = tp;
	};
};

class User {
public:
	int userId;

	User() {};
	User(int uid) {
		userId = uid;
	};

	vector<Weibo*> Weibos;
	vector<User*> fans;//粉丝
	vector<User*> followers;//关注

	bool isMyFollower(int uid);
	bool isFanOfMe(int uid);
	void unfollow(int uid);
	void unfan(int uid);

};

bool User::isFanOfMe(int uid) {
	for (User* fan : fans) {
		if (fan->userId == uid) {
			return true;
		}
	}
	return false;
};

bool User::isMyFollower(int uid) {
	for (User* follower : followers) {
		if (follower->userId == uid) {
			return true;
		}
	}
	return false;
};

void User::unfollow(int uid) {
	User* temp;
	for (int i = 0; i < followers.size(); i++) {
		if (followers[i]->userId == uid) {
			temp = followers[i];
			followers[i] = followers[followers.size() - 1];
			followers[followers.size() - 1] = temp;
			followers.pop_back();
			return;
		}
	}
};

void User::unfan(int uid) {
	User* temp;
	for (int i = 0; i < fans.size(); i++) {
		if (fans[i]->userId == uid) {
			temp = fans[i];
			fans[i] = fans[fans.size() - 1];
			fans[fans.size() - 1] = temp;
			fans.pop_back();
			return;
		}
	}
};
//函数头文件
User* createUser(vector<User*> userList, int uid);
User* getUserByUid(vector<User*> userList, int uid);

int main() {

	////调试用
	//FILE* ifs;
	//freopen_s(&ifs, "test5.in", "r", stdin);
	////

	//Weibo
	vector<Weibo*> WeiboList;
	vector<User*> userList;
	//
	int N;
	cin >> N;


	//输入元素
	int userId;
	int weiboId;
	int weiboType;
	int ReadType;
	int followerId, followeeId;
	int num;


	//在所有需要Uid的地方确认用户存在
	string cmd;
	User* user;
	User* followerUser;
	User* followeeUser;
	Weibo* weibo;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		//检查拼写
		if (cmd.compare("post") == 0) {
			cin >> userId >> weiboId >> weiboType;

			weibo = new Weibo(userId, weiboId, weiboType);
			user = getUserByUid(userList, userId);
			if (user == nullptr) {
				User* res = new User(userId);
				user = res;
				userList.push_back(res);
			}

			WeiboList.push_back(weibo);
			user->Weibos.push_back(weibo);
		}
		else if (cmd.compare("follow") == 0) {
			cin >> followerId >> followeeId;
			followerUser = getUserByUid(userList, followerId);
			followeeUser = getUserByUid(userList, followeeId);

			if (followerUser == nullptr) {
				User* res = new User(followerId);
				followerUser = res;
				userList.push_back(res);
			}

			if (followeeUser == nullptr) {
				User* res = new User(followeeId);
				followeeUser = res;
				userList.push_back(res);
			}


			//更新关注
			followerUser->followers.push_back(followeeUser);
			followeeUser->fans.push_back(followerUser);

		}
		else if (cmd.compare("unfollow") == 0) {
			cin >> followerId >> followeeId;
			followerUser = getUserByUid(userList, followerId);
			followeeUser = getUserByUid(userList, followeeId);

			if (followerUser == nullptr) {
				User* res = new User(followerId);
				followerUser = res;
				userList.push_back(res);
			}

			if (followeeUser == nullptr) {
				User* res = new User(followeeId);
				followeeUser = res;
				userList.push_back(res);
			}

			//取消关注
			followerUser->unfollow(followeeId);
			followeeUser->unfan(followerId);
		}
		else if (cmd.compare("getFollows") == 0) {
			cin >> userId;

			user = getUserByUid(userList, userId);
			if (user == nullptr) {
				User* res = new User(userId);
				user = res;
				userList.push_back(res);
			}

			cout << user->followers.size() << endl;
		}
		else if (cmd.compare("getFans") == 0) {
			cin >> userId;

			user = getUserByUid(userList, userId);
			if (user == nullptr) {
				User* res = new User(userId);
				user = res;
				userList.push_back(res);
			}

			cout << user->fans.size() << endl;

		}
		else if (cmd.compare("getWeibos") == 0) {
			cin >> userId;
			user = getUserByUid(userList, userId);
			if (user == nullptr) {
				User* res = new User(userId);
				user = res;
				userList.push_back(res);
			}
			cout << user->Weibos.size() << endl;
		}
		else if (cmd.compare("getRecent") == 0) {
			cin >> userId >> num >> ReadType;
			int size;
			int getNum = 0;
			int index = 0;

			user = getUserByUid(userList, userId);
			if (user == nullptr) {
				User* res = new User(userId);
				user = res;
				userList.push_back(res);
			}

			switch (ReadType)
			{
			case 0:
				//0查看自己的微博
				size = user->Weibos.size();
				for (int i = size - 1; getNum < num && i >= 0; i--) {
					Weibo* weibo = user->Weibos[i];
					if (weibo->userId == userId) {
						if (getNum == 0) {
							cout << weibo->weiboId;
						}
						else
						{
							cout << " " << weibo->weiboId;
						}
						getNum += 1;
					}
				}
				cout << endl;
				break;
			case 1:
				//1看朋友圈
				size = WeiboList.size();
				for (int i = size - 1; getNum < num && i >= 0; i--) {
					Weibo* weibo = WeiboList[i];
					//1. 自己的可见
					if (weibo->userId == userId) {
						if (getNum == 0) {
							cout << weibo->weiboId;
						}
						else
						{
							cout << " " << weibo->weiboId;
						}
						getNum += 1;
					}
					else if (weibo->type == 1 || weibo->type == 2) {
						if (user->isFanOfMe(weibo->userId) && user->isMyFollower(weibo->userId)) {
							//是朋友
							if (getNum == 0) {
								cout << weibo->weiboId;
							}
							else
							{
								cout << " " << weibo->weiboId;
							}
							getNum += 1;
						}
					}
				}
				cout << endl;
				break;
			case 2:
				//2查看关注的人的微博
				size = WeiboList.size();
				for (int i = size - 1; getNum < num && i >= 0; i--) {
					Weibo* weibo = WeiboList[i];
					//1. 自己的可见
					if (weibo->userId == userId) {
						if (getNum == 0) {
							cout << weibo->weiboId;
						}
						else
						{
							cout << " " << weibo->weiboId;
						}
						getNum += 1;
					}
					else if (weibo->type == 1) {
						//是朋友圈可见，但彼此是朋友；
						if (user->isFanOfMe(weibo->userId) && user->isMyFollower(weibo->userId)) {
							//是朋友
							if (getNum == 0) {
								cout << weibo->weiboId;
							}
							else
							{
								cout << " " << weibo->weiboId;
							}
							getNum += 1;
						}
					}
					else if (weibo->type == 2) {
						//微博本身是粉丝可见的

						if (user->isMyFollower(weibo->userId)) {
							//自己关注了
							if (getNum == 0) {
								cout << weibo->weiboId;
							}
							else
							{
								cout << " " << weibo->weiboId;
							}
							getNum += 1;
						}
					}
				}
				cout << endl;
				break;
			default:
				break;
			}
		}
		else
		{
			cout << "Error Command!" << endl;
		}
	}
}

User* createUser(vector<User*> userList, int uid) {
	User* res = new User(uid);
	userList.push_back(res);
	return res;
}

User* getUserByUid(vector<User*> userList, int uid)
{
	for (User* user : userList) {
		if (user->userId == uid) {
			return user;
		}
	}


	return nullptr;
}

//#include<iostream>
//#include<vector>
//
//using namespace std;
//class message {
//	public:
//		message() {};
//
//		message(int mid,int uid,int type,int time) {
//			this->mid = mid;
//			this->uid = uid;
//			this->type = type;
//			this->time = time;
//		}
//	int mid;
//	int uid;
//	int type;
//	int time;
//};
//
//class user {
//public:
//	user() {};
//
//	user(int uid) {
//		this->uid = uid;
//	};
//
//	int uid;
//	vector<int> follow=vector<int>();
//	vector<int> fans= vector<int>();
//	vector<message> weibo= vector<message>();
//	vector<int> circle= vector<int>();
//
//	void set_circle() {
//		circle.clear();
//		for (int i = 0; i < follow.size(); i++)
//		{
//			for (int j = 0; j < fans.size(); j++)
//			{
//				if (follow[i] == fans[j]) {
//					circle.push_back(follow[i]);
//					break;
//				}
//			}
//		}
//
//	}
//
//	void getfollows(vector<string>* res) {
//		string temp = "" + this->follow.size();
//		(*res).push_back(temp);
//	}
//
//	void getfans(vector<string>* res) {
//		string temp = "" + this->fans.size();
//		(*res).push_back(temp);
//	}
//
//	void getweibos(vector<string>* res) {
//		string temp = "" + this->weibo.size();
//		(*res).push_back(temp);
//	}
//
//	void followe(int oid) {
//		this->follow.push_back(oid);
//	}
//
//	void unfollowe(int oid) {
//		int pos = -1;
//		for (int i = 0; i < this->follow.size(); i++)
//		{
//			if (oid == follow[i]) {
//				pos = i;
//				break;
//			}
//		}
//		this->follow.erase(follow.begin()+pos);
//	}
//
//	void followed(int oid) {
//		this->fans.push_back(oid);
//	}
//
//	void unfollowed(int oid) {
//		int pos = -1;
//		for (int i = 0; i < this->fans.size(); i++)
//		{
//			if (oid == fans[i]) {
//				pos = i;
//				break;
//			}
//		}
//		this->fans.erase(fans.begin() + pos);
//	}
//
//	void post(int mid, int type, int time) {
//		message mes =message(mid, this->uid, type, time);
//		this->weibo.push_back(mes);
//	}
//
//};
//
//user& find(vector<user>& users, int uid,user temp) {
//	int res = -1;
//	if(!users.empty())
//	for (int i = 0; i < users.size(); i++) {
//		if (users[i].uid == uid) {
//			res = i;
//			break;
//		}
//	}
//	if (res == -1) {
//		temp = user(uid);
//		users.push_back(temp);
//		user& copy = users.back();
//		if (users.size() == 1)
//			copy = users[0];
//		return copy;
//	}
//	else {
//		user& copy = users[res];
//		return copy;
//	}
//}
//
//
//int main() {
//	int n; string order;
//	cin >> n;
//	vector<user> users;
//	vector<string> res;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> order;
//		if (order[0] == 'p') {
//			int uid, mid, type;
//			user temp=user();
//			cin >> uid >> mid >> type;
//			user& user1 = find(users, uid,temp);
//			user1.post(mid,type,i);
//		}
//		else if (order[0] == 'f') {
//			int uid1, uid2;
//			cin >> uid1 >> uid2;
//			user temp1 = user();
//			user& user1 = find(users, uid1, temp1);
//			user1.followe(uid2);
//			user temp2 = user();
//			user& user2 = find(users, uid2,temp2);
//			user2.followed(uid1);
//		}
//		else if (order[0] == 'u') {
//			int uid1, uid2;
//			cin >> uid1 >> uid2;
//			user temp1 = user();
//			user temp2 = user();
//			user& user1 = find(users, uid1, temp1);
//			user& user2 = find(users, uid2, temp2);
//			user1.unfollowe(uid2);
//			user2.unfollowed(uid1);
//		}
//		else {
//			if (order[3] == 'W') {
//				int uid;
//				cin >> uid;
//				user temp = user();
//				user& user1 = find(users, uid, temp);
//				user1.getweibos(&res);
//			}
//			else if (order[3] == 'R') {
//				//查看最近微博
//			}
//			else {
//				if (order[4] == 'a') {
//					int uid;
//					cin >> uid;
//					user temp = user();
//					user& user1 = find(users, uid, temp);
//					user1.getfans(&res);
//				}
//				else if (order[4] == 'o') {
//					int uid;
//					cin >> uid;
//					user temp = user();
//					user& user1 = find(users, uid, temp);
//					user1.getfollows(&res);
//				}
//			}
//		}
//	}
//
//	for (int i = 0; i <res.size(); i++)
//	{
//		cout <<res[i] << endl;
//	}
//	return 0;
//}