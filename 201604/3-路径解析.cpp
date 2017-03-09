#include <iostream>
#include <string>
using namespace std;
int main(){
	int num;
	string curDir;
	cin >> num >> curDir;
	getchar();//读入换行符
	for (int i = 0; i<num; i++){
		string line;
		getline(cin, line);
		int pos;
		if (line[0] != '/'){//不是绝对路径，添加到当前目录下
			line = curDir + "/" + line;
		}
		if (line.size() == 0){
			line = curDir;
		}
		while ((pos = line.find("//")) != -1){		// 除去多个///
			int count = 2;
			while (line[pos + count] == '/'){//记录更多/ 一并删除
				count++;
			}
			line.erase(pos, count - 1);//保留最后1个/
		}
		while ((pos = line.find("/../")) != -1){// 除去../
			if (pos == 0){//根目录的上一级是它本身
				line.erase(pos + 1, 3);
			}
			else{
				int spos;
				spos = line.rfind("/", pos - 1);//倒序寻找第一个/
				line.erase(spos, pos - spos + 3);//消除之间全部内容和../
			}
		}
		while ((pos = line.find("/./")) != -1){	// 除去./    ./表示相对路径，只会以/./形式出现
			line.erase(pos + 1, 2);
		}
		// 除去最后一个/
		if (line.size()>1 && line[line.size() - 1] == '/')
			line.erase(line.size() - 1);
		cout << line << endl;
	}
	return 0;
}
