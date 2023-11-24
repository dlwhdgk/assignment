#include <iostream>
#include "Circle.h"
#include "Line.h"
#include "Rect.h"
#include "Shape.h"
#include <vector>
using namespace std;

class UI {
public:
    static int selectMenu() {
        int n;
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> n;
        return n;
    }
    static int selectShape() {
        int n;
        cout << "선:1, 원:2, 사각형:3 >> ";
        cin >> n;
        return n;
    }
    static int selectDelIndex() {
        int n;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> n;
        return n;
    }
    static void showAll(vector<Shape*>& v, vector<Shape*>::iterator& it) {
        int i = 0;
        for (it = v.begin(); it != v.end(); it++, i++) {
            cout << i << ": ";
            v.at(i)->paint();
        }
    }
};
class GraphicEditor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    GraphicEditor() {
        cout << "그래픽 에디터입니다.\n";
        start();
    }
    void start() {
        while (true) {
            int n;
            n = UI::selectMenu();
            switch (n) {
            case 1: //도형선택
                n = UI::selectShape();
                switch (n) {
                case 1:
                    v.push_back(new Line());
                    break;
                case 2:
                    v.push_back(new Circle());
                    break;
                case 3:
                    v.push_back(new Rect());
                    break;
                default:
                    cout << "숫자를 제대로 입력하시오." << endl;
                    break;
                }
                break;
            case 2: { //도형지우기
                n = UI::selectDelIndex();
                if (n >= v.size() || n < 0) { // 없는 인덱스에 대한 예외처리  
                    cout << "숫자를 제대로 입력하시오." << endl;
                    break;
                }
                it = v.begin();
                Shape* tmp = *(it + n);
                v.erase(it + n);
                delete tmp;
                break;
            }
            case 3: //선택한 도형 보이기
                UI::showAll(v, it);
                break;
            case 4: //종료
                return;
            default:
                cout << "숫자를 제대로 입력하시오." << endl;
                break;
            }
        }
    }

};
int main() {
    new GraphicEditor();
}
