#include <iostream>
using namespace std;
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"

class UI {
public:
	static int getMenu() {
		int key;
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
		cin >> key;
		return key;
	}
	static int getShapeInsert() {
		int key;
		cout << "선:1, 원:2, 사각형:3 >>";
		cin >> key;
		return key;
	}
	static int getShapeDelete() {
		int key;
		cout << "삭제하고자 하는 도형의 인덱스 >>";
		cin >> key;
		return key;
	}
};

class GraphicEditor {
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() { pStart = pLast = NULL; }
	void insertItem(int type) {
		Shape* p = NULL;
		switch (type) {
		case 1:
			p = new Line();
			break;
		case 2:
			p = new Circle();
			break;
		case 3:
			p = new Rect();
			break;
		default:
			cout << "없는 수입니다" << endl;
			break;
		}
		if (pStart == NULL) {
			pStart = p;
			pLast = p;
			return;
		}
		pLast->add(p);
		pLast = pLast->getNext();
	}
	void deleteItem(int index) {
		Shape* pre = pStart;
		Shape* tmp = pStart;
		if (pStart == NULL) {
			cout << "도형이 없습니다" << endl;
			return;
		}
		for (int i = 0; i < index; i++) {
			pre = tmp;
			tmp = tmp->getNext();
		}
		if (tmp == pStart) {
			pStart = tmp->getNext();
			delete tmp;
		}
		else {
			pre->add(tmp->getNext());
			delete tmp;
		}
	}
	void show() {
		Shape* tmp = pStart;
		int i = 0;
		while (tmp != NULL) {
			cout << i++ << ": ";
			tmp->paint();
			tmp = tmp->getNext();
		}
	}
	void run() {
		cout << "그래픽 에디터입니다." << endl;
		int menu, index, type;
		while (true) {
			menu = UI::getMenu();
			switch (menu) {
			case 1:
				type = UI::getShapeInsert();
				insertItem(type);
				break;
			case 2:
				index = UI::getShapeDelete();
				deleteItem(index);
				break;
			case 3:
				show();
				break;
			case 4:
				return;
			default:
				cout << "숫자를 제대로 입력하시오" << endl;
			}
		}
	}
};

int main() {
	GraphicEditor graphicEditor;
	graphicEditor.run();

	return 0;
}
