class Solution {
  public:
    /*
    - this is a multisource shortest path algortithm
    - also helps you detect a negative cycle
    - from any source to any source we find the shortest path hence why we store it in a matrix

    steps:
    1. make the -1 values in the matrix 1e9 & the i==j values 0
    2. 3d nested loop to get the min values
    3. loop for i==j diagonal line in the matrix if is negative means a neg cycles
    4. reset in the matrix the 1e9 to -1 like it was originally 
    */
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    //we're using a matrix need space to store it in this case it is n2
	    int n = matrix.size();
	    for(int i=0; i<n; i++){
    	    for(int j=0; j<n; j++){
    	        if(matrix[i][j] == -1){
    	            matrix[i][j] = 1e9;
    	        }
    	        if(i==j) matrix[i][j] = 0;
    	    }
	    }
	    //time complexity it is n3
	    for(int k=0; k<n; k++){
	        for(int i=0; i<n; i++){
	            for(int j=0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
	            }
	        }
	    }

	   // to check if thers a negative cycle
	    for(int i=0; i<n; i++){
	        if(matrix[i][i]<0){
	            cout<< "negative cycle";
	        }
	    }

	    for(int i=0; i<n; i++){
    	    for(int j=0; j<n; j++){
    	        if(matrix[i][j] == 1e9){
    	            matrix[i][j] = -1;
    	        }
	        }
	    }
	}
};
