class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int prevcolor = image[sr][sc];
        dfs(image,sr,sc,newColor,prevcolor);
        return image;
    }
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int prevcolor)
    {
        if(sr<0 || sc<0 || sr>=image.size() || sc>=image[0].size())
            return;
        if(image[sr][sc]!=prevcolor)
            return;
        if(image[sr][sc]==newColor)
            return;
        image[sr][sc] = newColor;
        dfs(image,sr-1,sc,newColor,prevcolor);
        dfs(image,sr+1,sc,newColor,prevcolor);
        dfs(image,sr,sc-1,newColor,prevcolor);
        dfs(image,sr,sc+1,newColor,prevcolor);
    }
};
