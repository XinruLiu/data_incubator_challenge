#include <iostream>
#include <vector>

using namespace std;

class grid{
    private:
        int d;
        int n;
        int m;
        vector <int> v;
        
    public:
        void readInData();
        vector<vector<int>> walkCount(vector<int>, int);
        void loopDim();
};


void grid::readInData(){
    cout << "d = ";
    cin >> d;
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;
    vector<int> vec(d);
    v=vec;
    cout << "Input starting poit: ";
    for(int i = 0; i < d; i++){
        cin >> v.at(i);
    }
    
}

void grid::loopDim(){
    vector<vector<int>> finalList = walkCount(v, m);
    cout << finalList.size() << endl;
}

vector<vector<int>> grid::walkCount(vector<int> v, int length){
    vector<vector<int>> pointListNew;
    //base case
    if(length == 0){
        pointListNew.push_back(v);
        return pointListNew;
    }
    else{
        //inductive assumption
        vector<vector<int>> pointList = walkCount(v, length-1);
        //helper
        for (int j = 0; j < pointList.size(); j++){
            vector<int> point = pointList[j];
            for(int i = 0; i < d; i++){
                if (point[i] == 0){
                    vector <int> newPoint;
                    newPoint = point;
                    newPoint[i]++;
                    pointListNew.push_back(newPoint);
                }
                else{
                    vector<int> tempvec1 = point;
                    vector<int> tempvec2 = point;
                    tempvec1[i]--;
                    pointListNew.push_back(tempvec1);
                    if(tempvec2[i] < n){
                        tempvec2[i]++;
                        pointListNew.push_back(tempvec2); 
                    }
                    else{
                        tempvec2[i]--;
                        pointListNew.push_back(tempvec2); 
                    }       
                }
            }
        }
        return pointListNew;
    }
}


int main(){
    grid myGrid;
    myGrid.readInData();
    myGrid.loopDim();
    return 0;
}

