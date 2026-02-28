#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits>

/**
 * Solves the minimum distance problem in O(N) time complexity.
 * The distance for any triplet i < j < k of the same value simplifies to 2 * (k - i).
 * We track the indices of the two most recent occurrences (second_last and last)
 * to find the minimum distance from consecutive triplets.
 */
class Solution {
public://O(N) is tc and sc is O(N)
    /**
     * Calculates the minimum distance based on the formula 2 * (k - i).
     * * @param nums The input array of integers.
     * @return The minimum distance found, or -1 if no number appears three times.
     */
    int minimumDistance(const std::vector<int>& nums) {
        // Map to store the most recent index (idx_m+1) of a number
        std::unordered_map<int, int> last_seen;
        // Map to store the second most recent index (idx_m) of a number
        std::unordered_map<int, int> second_last_seen;
        
        // Initialize minimum distance to a very large value
        int min_distance = std::numeric_limits<int>::max();

        for (int i = 0; i < nums.size(); ++i) {
            int value = nums[i];

            if (second_last_seen.count(value)) {
                // Case 1: Third (or more) occurrence found.
                // 'i' is the third index (k).
                // 'second_last_seen[value]' is the first index of this triplet (i).
                
                int first_index = second_last_seen.at(value);
                // Calculate distance: 2 * (k - i)
                int current_dist = 2 * (i - first_index);
                
                // Update global minimum
                min_distance = std::min(min_distance, current_dist);
                
                // Slide the window:
                // The old 'last' becomes the new 'second last'
                second_last_seen[value] = last_seen.at(value);
                // The current index 'i' becomes the new 'last'
                last_seen[value] = i;
                
            } else if (last_seen.count(value)) {
                // Case 2: Second occurrence found.
                // Promote the first index to 'second_last_seen'
                second_last_seen[value] = last_seen.at(value);
                // Update 'last_seen' to the current index
                last_seen[value] = i;
                
            } else {
                // Case 3: First occurrence found.
                // Just record its index in 'last_seen'
                last_seen[value] = i;
            }
        }

        // If min_distance is still the max value, no triplet was found, return -1.
        if (min_distance == std::numeric_limits<int>::max()) {
            return -1;
        } else {
            return min_distance;
        }
    }
};
