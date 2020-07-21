#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		int half = numbers.size() / 2;
		unordered_map<int, int> map;
		for (int i = 0; i < numbers.size(); i++) {
			auto it = map.find(numbers[i]);
			if (it == map.end()) { //没找到
				map.insert(make_pair(numbers[i], 1));
			}
			else { //找到了
				map[numbers[i]]++;
			}
			if (map[numbers[i]] > half) {
				return numbers[i];
			}
		}
		return 0;
	}
};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		sort(numbers.begin(), numbers.end());
		int half = numbers.size() / 2;
		int count = 0;
		for (const auto e : numbers) {
			if (e == numbers[half])
				count++;
		}
		return count > half ? numbers[half] : 0;
	}
};

class Solution {
public:
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty()) {
			return 0;
		}
		int tmp = numbers[0];
		int time = 1;
		for (int i = 1; i < numbers.size(); i++) {
			if (time == 0) {
				tmp = numbers[i];
				time = 1;
			}
			if (numbers[i] == tmp) {
				time++;
			}
			else {
				time--;
			}
		}
		time = 0;
		for (const auto e : numbers) {
			if (e == tmp) {
				time++;
			}
		}
		int half = numbers.size() / 2;
		return time > half ? tmp : 0;
	}
};

class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ')
				count++;
		}
		char* old_end = str + length;
		char* new_end = str + length + 2 * count;
		while (old_end >= str && new_end >= str) {
			if (*old_end != ' ') {
				*new_end = *old_end;
				old_end--;
				new_end--;
			}
			else {
				*new_end-- = '0';
				*new_end-- = '2';
				*new_end-- = '%';
				old_end--;
			}
		}
	}
};

class Solution {
public:
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		while (head) {
			v.push_back(head->val);
			head = head->next;
		}
		reverse(v.begin(), v.end());
		return v;
	}
};

class Solution {
public:
	TreeNode* reConstructBinaryTreeCore(vector<int> pre, int pre_start, int pre_end, vector<int> vin, int vin_start, int vin_end) {
		if (pre_start > pre_end || vin_start > vin_end)
			return nullptr;
		TreeNode* root = new TreeNode(pre[pre_start]);
		for (int i = vin_start; i <= vin_end; i++) {
			if (vin[i] == pre[pre_start]) {
				root->left = reConstructBinaryTreeCore(pre, pre_start + 1, pre_start + i - vin_start, vin, vin_start, i - 1);
				root->right = reConstructBinaryTreeCore(pre, pre_start + i - vin_start + 1, pre_end, vin, i + 1, vin_end);
				break;
			}
		}
		return root;
	}
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.empty() || vin.empty() || pre.size() != vin.size())
			return nullptr;
		return reConstructBinaryTreeCore(pre, 0, pre.size() - 1, vin, 0, vin.size() - 1);
	}
};