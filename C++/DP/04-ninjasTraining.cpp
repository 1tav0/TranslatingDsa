#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  // Recursive Solution
  int helper1(int day, int last, vector<vector<int>> &points){
    int maxi = -1e9;
    if(day == 0){
      for(int task=0; task<3; task++){
        if(task != last){
          maxi = max(maxi, points[day][task]);
        }
      }
      return maxi;
    }

    maxi = -1e9;
    for(int task=0; task<3; task++){
      if(task != last){
        int pts = points[day][task] + helper1(day-1, task, points);
        maxi = max(maxi, pts);
      }
    }
    return maxi;
  }
  int ninjaTraining1(int n, vector<vector<int>>& points){
    return helper1(n-1, 3, points);
  }

  /* ------------------------------------------------------------------- */

  //Memoization
  int helper2(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp){
    int maxi = -1e9;
    if(day == 0){
      for(int task=0; task<3; task++){
        if(task != last){
          maxi = max(maxi, points[day][task]);
        }
      }
      return maxi;
    }

    if(dp[day][last] != -1) return dp[day][last];

    maxi = -1e9;
    for(int task=0; task<3; task++){
      if(task != last){
        int pts = points[day][task] + helper2(day-1, task, points, dp);
        maxi = max(maxi, pts);
      }
    }
    return dp[day][last] = maxi;
  }

  int ninjaTraining2(int n, vector<vector<int>>& points){
    vector<vector<int>> dp(n+1, vector<int>(4, -1));
    return helper2(n-1, 3, points, dp);
  }

  /* ------------------------------------------------------------------- */

  //Tabulation
  int ninjaTraining3(int n, vector<vector<int>>& points){
    vector<vector<int>> dp(n+1, vector<int>(4, -1));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][3]));

    for(int day=1; day<n; day++){
      for(int last=0; last<4; last++){
        int maxi = -1e9;
        for(int task=0; task<3; task++){
          if(last != task){
            int pts = points[day][task] + dp[day-1][task];
            maxi = max(maxi, pts);
          }
        }
        dp[day][last] = maxi;
      }
    }
    return dp[n-1][3];
  }

  /* ------------------------------------------------------------------- */

  // Space Optimization
  int ninjaTraining4(int n, vector<vector<int>>& points){
    vector<int> prev(4, -1);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1],points[0][3]));
    for(int day=1; day<n; day++){
      vector<int> current(4, -1);
      for(int last=0; last<4; last++){
        for(int task=0; task<3; task++){
          if(task != last){
            int pts = points[day][task] + prev[task];
            current[last] = max(current[last], pts);
          }
        }
      }
      prev = current;
    }
    return prev[3];
  }

};

ostream& operator<<(ostream& os, vector<vector<int>> arr){
  int n = arr.size();
  int m = arr[0].size();
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      os << arr[i][j] << " ";
    }
    os << endl;
  }
  return os;
}

int main(){
  vector<vector<int>> points = { {1, 2, 5}, {3, 1, 1} ,{3, 3, 3} };
  int n = points.size();
  cout << "The list of points are: " << endl << points << endl;
  Solution obj;
  int ans = obj.ninjaTraining4(n,points);
  cout << "The maximum number of merit points that Ninja can earn is: " << ans;
  return 0;
}
