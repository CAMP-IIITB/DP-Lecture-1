#define INF INT_MAX

// Helper function for update_min_and_second_min()
void update_min_and_second_min(int x, int &min1, int &min2){
  if(x <= min1){
    min2 = min1;
    min1 = x;
  }
  else if(x < min2){
    min2 = x;
  }
  return;
}

// Computes the minimum and second minimum values in a vector.
void update_min_and_second_min(const vector<int> &v, int &min1, int &min2){
  for(int x : v) update_min_and_second_min(x, min1, min2);
  return
}

// Computes the minimum cost to paint a wall such that no two adjacent
// slabs of the wall are assigned the same color. Works in
// O(num_slabs * num_colors) time and uses O(num_colors) memory.
int paint_wall_with_min_cost(const vector<vector<int>> &costs) {
  // Input validation.
  int num_slabs = costs.size();
  if(num_slabs == 0){
    throw;
  }
  
  int num_colors = costs[0].size();
  if(num_colors == 0){
    throw;
  }
  
  if(num_colors == 1 and num_slabs > 1){
    throw;
  }
  
  vector<vector<int>> dp_table(2);
  
  // Base case initialization.
  dp_table[0] = costs[0];  
  
  // Find the minimum and second minimum costs for the first slab.
  int min1 = INF, min2 = INF;
  update_min_and_second_min(dp[0], min1, min2);
  
  // Compute the transitions for each slab from 1 to num_slabs-1
  for(int i = 1; i < num_slabs; i++){
    // Apply the reccurrence relation.
    for(int j = 0; j < num_colors; j++){
        dp_table[1][j] = ((dp_table[0][j] == min1) ? min2 : min1) + costs[i][j];
      }
    }
    // Exchange rows.
    swap(dp_table[0], dp_table[1]);
    
    // Recompute the minimum and second minimum for the i-th slab.
    min1 = min2 = INF;
    update_min_and_second_min(dp_table[0], min1, min2);
  }
  return min1;
}

