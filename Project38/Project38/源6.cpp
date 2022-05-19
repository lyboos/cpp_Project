#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<list>
#include<vector>

//�û����Է���΢������ע/ȡ�������û����鿴�û��Ĺ�ע������˿ ����΢�������鿴�����΢��

using namespace std;

//���������е�id��֤Ϊint���͵���������΢��id��֤���ظ� ������Ϊ΢��������ʱ����post������Ⱥ�˳��һ��
//��ʾ������ʵ�ַ�������ע�Ȼ��������Լ��鿴��ע������˿����΢�������õ�������������

//�����ע==����Ȧ
class Weibo {
public:
	int userId;
	int weiboId;
	int type; //0������Լ��ɼ���1�������Ȧ�ɼ���2�����˿�ɼ� 

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
	vector<User*> fans;//��˿
	vector<User*> followers;//��ע

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
//����ͷ�ļ�
User* createUser(vector<User*> userList, int uid);
User* getUserByUid(vector<User*> userList, int uid);

int main() {

	////������
	//FILE* ifs;
	//freopen_s(&ifs, "test5.in", "r", stdin);
	////

	//Weibo
	vector<Weibo*> WeiboList;
	vector<User*> userList;
	//
	int N;
	cin >> N;


	//����Ԫ��
	int userId;
	int weiboId;
	int weiboType;
	int ReadType;
	int followerId, followeeId;
	int num;


	//��������ҪUid�ĵط�ȷ���û�����
	string cmd;
	User* user;
	User* followerUser;
	User* followeeUser;
	Weibo* weibo;
	for (int i = 0; i < N; i++) {
		cin >> cmd;
		//���ƴд
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


			//���¹�ע
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

			//ȡ����ע
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
				//0�鿴�Լ���΢��
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
				//1������Ȧ
				size = WeiboList.size();
				for (int i = size - 1; getNum < num && i >= 0; i--) {
					Weibo* weibo = WeiboList[i];
					//1. �Լ��Ŀɼ�
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
							//������
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
				//2�鿴��ע���˵�΢��
				size = WeiboList.size();
				for (int i = size - 1; getNum < num && i >= 0; i--) {
					Weibo* weibo = WeiboList[i];
					//1. �Լ��Ŀɼ�
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
						//������Ȧ�ɼ������˴������ѣ�
						if (user->isFanOfMe(weibo->userId) && user->isMyFollower(weibo->userId)) {
							//������
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
						//΢�������Ƿ�˿�ɼ���

						if (user->isMyFollower(weibo->userId)) {
							//�Լ���ע��
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
//				//�鿴���΢��
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