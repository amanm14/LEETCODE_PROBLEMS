class Solution {
public: // tc --> O(N*M) sc--> O(N*M) for matrix O(N*M) = O(N*M) is for recursion
    void dfs(vector<vector<int>>&img,vector<vector<int>>& newIm,int sr,int sc,int col,int inCol,
    int delR[],int delC[]){
        newIm[sr][sc]=col;
        for(int i=0;i<4;i++){
            int nr=sr+delR[i];
            int nc=sc+delC[i];
            if(nr>=0&&nr<newIm.size()&&nc>=0&&nc<newIm[0].size()&&
            img[nr][nc]==inCol&&newIm[nr][nc]!=col){//img[nr][nc]==inCol --> so we can only check nrighbours only if they are equal to inintal value questions conditoin
                dfs(img,newIm,nr,nc,col,inCol,delR,delC);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        vector<vector<int>>newImg=image;
        int inColor=image[sr][sc];

       int delR[]={-1,0,+1,0};
        int delC[]={0,+1,0,-1};

        dfs(image,newImg,sr,sc,color,inColor,delR,delC);
        return newImg;
    }
};
