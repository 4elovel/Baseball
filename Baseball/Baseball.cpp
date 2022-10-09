#include <iostream>
#include <vector>
#include <string>

using namespace std;

void menu() {
	cout << "Your options:\n";
	cout << "Integer - write new score equal this number\n";
	cout << "+ - new score equal sum of two numbers before\n";
	cout << "d - new score equal 2x of number before\n";
	cout << "c - cancel last number\n";
	cout << "Write your text->\n";
}

int main()
{
	char a = 1;
	vector <int> vec;
	string text;
	string subtext;
	string separator = " ";
	int f_pos = 0;
	int s_pos = 0;
	menu();

	getline(cin,text);
	text += separator;

	while (f_pos != text.size() && s_pos != text.size())
	{
		subtext = "";
		s_pos = text.find(separator, f_pos);
		subtext = text.substr(f_pos, s_pos - f_pos);

		if (subtext == "+" && vec.size() > 1)
		{
			vec.push_back(vec[vec.size() - 1] + vec[vec.size() - 2]);
		}

		else if (subtext == "d" && !vec.empty()) {
			vec.push_back((vec[vec.size() - 1]) * 2);
		}

		else if (subtext == "c" && !vec.empty())
		{
			vec.pop_back();
		}

		else if (stoi(subtext) > -333 && stoi(subtext) < 333)
		{
			vec.push_back(stoi(subtext));
		}

		else
		{
			cout << "\nWRONG INPUT\n";
			return 0;
		}

		f_pos = s_pos;
		f_pos++;
	}
	for (size_t i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
}
