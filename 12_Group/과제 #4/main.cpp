#include <iostream>
using namespace std;

class Coffee {
	int coffee, sugar, cream, water, cup;
public:
	Coffee() { coffee = 3, sugar = 3, cream = 3, water = 3, cup = 3; }
	bool lack() {
		if (cup == 0)
			return true;
		else
			return false;
	}
	void normal() {
		if (lack())
			cout << "재료 부족" << endl;
		else {
			coffee--, cream--, water--, cup--;
			cout << "맛있는 보통 커피 나왔습니다~~" << endl;
		}
	}
	void sugar_coffee() {
		if (lack())
			cout << "재료 부족" << endl;
		else {
			coffee--, sugar--, water--, cup--;
			cout << "맛있는 설탕 커피 나왔습니다~~" << endl;
		}
	}
	void black_coffee() {
		if (lack())
			cout << "재료 부족" << endl;
		else {
			coffee--,  water--, cup--;
			cout << "맛있는 블랙 커피 나왔습니다~~" << endl;
		}
	}
	void fill() { 
		coffee = 3, sugar = 3, cream = 3, water = 3, cup = 3; 
		cout << "모든 통을 채웁니다.~~" << endl;
	}
	void showAll() {
		cout << "Coffee   ";
		for (int i = 0; i < coffee; i++)
			cout << "*";
		cout << endl;
		cout << "Sugar    ";
		for (int i = 0; i < sugar; i++)
			cout << "*";
		cout << endl;
		cout << "CREAM    ";
		for (int i = 0; i < cream; i++)
			cout << "*";
		cout << endl;
		cout << "Water    ";
		for (int i = 0; i < water; i++)
			cout << "*";
		cout << endl;
		cout << "Cup      ";
		for (int i = 0; i < cup; i++)
			cout << "*";
		cout << endl;
		cout << endl;
	}
};
int main() {
	Coffee c;
	int input = 0;
	cout << "------명품 커피 자판기켭니다.------" << endl;
	while (true) {
		c.showAll();
		cout << "보통 커피:0, 설탕 커피:1, 블랙 커피:2, 채우기:3, 종료:4>>";
		cin >> input;
		switch (input) {
		case 0:
			c.normal();
			break;
		case 1:
			c.sugar_coffee();
			break;
		case 2:
			c.black_coffee();
			break;
		case 3:
			c.fill();
			break;
		case 4:
			return 0;
		
		}
	}
}
