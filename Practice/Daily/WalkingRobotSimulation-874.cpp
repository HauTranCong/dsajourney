class Solution {
private:
    void isGetBlocked(int& x, int& y, int dir, const vector<vector<int>>& obstacles) {
        for(const vector<int>& coordinate : obstacles) {
            if(dir == 0 && x == coordinate[0] && y >= coordinate[1] && coordinate[1] >= 0) {
                y = coordinate[1] - 1;
                return;
            } else if(dir == 1 && y == coordinate[1] && x >= coordinate[0] && coordinate[0] >= 0) {
                x = coordinate[0] - 1;  
                return;
            } else if(dir == 2 && x == coordinate[0] && y <= coordinate[1] && coordinate[1] <= 0) {
                y = coordinate[1] + 1;
                return;
            } else if(dir == 3 && y == coordinate[1] && x <= coordinate[0] && coordinate[0] <= 0) {
                x = coordinate[0] + 1;
                return;
            }
        }
    }
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // 0 1 2 3 -> N E S W
        int dir = 0;
        int ans = INT_MIN;
        int xRobot = 0, yRobot = 0;
        for(int i = 0; i < commands.size(); ++i) {
            if(commands[i] == -2) {
                dir -= 1;
                if(dir < 0)
                    dir = 3;
                continue;
            } else if(commands[i] == -1) {
                dir += 1;
                if(dir > 3)
                    dir = 0;
                continue;
            } else if(commands[i] >= 1 && commands[i] <= 9) {
                if(dir == 0)
                    yRobot += commands[i];
                else if(dir == 1)
                    xRobot += commands[i];
                else if(dir == 2)
                    yRobot -= commands[i];
                else
                    xRobot -= commands[i];
                isGetBlocked(xRobot, yRobot, dir, obstacles);
            }
            cout << xRobot << " " << yRobot << "\n";
            int square = pow(xRobot, 2) + pow(yRobot, 2);
            ans = max(ans,  square);
        }
        return ans;
    }
};

/*
            North                   +Y
    West    Robot   East        -X   O   +X
            South                   -Y
*/