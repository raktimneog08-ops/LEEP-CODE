class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> secret_counts(10, 0);
        vector<int> guess_counts(10, 0);

        for (int i = 0; i < secret.length(); ++i) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                secret_counts[secret[i] - '0']++;
                guess_counts[guess[i] - '0']++;
            }
        }

        for (int d = 0; d < 10; ++d) {
            cows += min(secret_counts[d], guess_counts[d]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};