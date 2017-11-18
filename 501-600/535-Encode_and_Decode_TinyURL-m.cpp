// TinyURL is a URL shortening service where you enter a URL such as
// https://leetcode.com/problems/design-tinyurl and it returns a short URL such
// as http://tinyurl.com/4e9iAk.
// Design the encode and decode methods for the TinyURL service. There is no
// restriction on how your encode/decode algorithm should work. You just need to
// ensure that a URL can be encoded to a tiny URL and the tiny URL can be
// decoded to the original URL.

// Just the simplest one
class Solution {
    map<int, string> data;
    int cnt = 0;
    
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        data.insert({cnt, longUrl});
        return to_string(cnt++);
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return data[stoi(shortUrl)];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));