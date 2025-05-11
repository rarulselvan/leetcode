class Solution 
{
public:
     vector<int> parent;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        int n = accounts.size();
        parent.resize(n);
        for (int i = 0; i < n; ++i) 
            parent[i] = i;
      
        // Map to store email to the index of the account it belongs to
        unordered_map<string, int> emailToIdx;
      
        // Iterate through each account to union emails and assign them a common parent index
        for (int i = 0; i < n; ++i) 
        {
            for (int j = 1; j < accounts[i].size(); ++j) 
            {
                string email = accounts[i][j];
                if (emailToIdx.count(email)) 
                {
                    // Union operation: merge the sets containing these two emails
                    parent[find(i)] = find(emailToIdx[email]);
                } 
                else 
                {
                    // Assign the current index to the unique email
                    emailToIdx[email] = i;
                }
            }
        }
      
        // Map to store the root index of each account and the associated unique emails
        unordered_map<int, unordered_set<string>> mergedAccounts;
        for (int i = 0; i < n; ++i)
         {
            for (int j = 1; j < accounts[i].size(); ++j) 
            {
                string email = accounts[i][j];
                // Insert the email into the set that belongs to the root parent of i
                mergedAccounts[find(i)].insert(email);
            }
        }
      
        // Prepare the final result from the merged accounts
        vector<vector<string>> result;
        for (auto& [i, emails] : mergedAccounts) 
        {
            vector<string> account;
            account.push_back(accounts[i][0]); // Add the name of the account owner
            account.insert(account.end(), emails.begin(), emails.end()); // Add all the merged emails
            sort(account.begin() + 1, account.end()); // Sort the emails
            result.push_back(account); // Add this list to the results
        }
      
        return result;
    }

    // The method to find the representative of the set that element x belongs to
    int find(int x) 
    {
        if (parent[x] != x) 
        {
            // Path compression: update the parent to the representative of the set for faster future lookups
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};