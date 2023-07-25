class Solution {
private:
    int bs(int l, int r, vector<int>& arr){
        int mid = l+(r-l)/2;
        if(mid==0){
            if(arr[mid]>arr[mid+1]) return mid;
            else return bs(mid+1,r,arr);
        }
        if(mid==arr.size()-1){
            if(arr[mid]>arr[mid-1]) return mid;
            else return bs(l,mid-1,arr);
        }
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) return mid;
        else if(arr[mid]<arr[mid-1]) return bs(l,mid-1,arr);
        else if(arr[mid]<arr[mid+1]) return bs(mid+1,r,arr);
        return 0;
    }
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        return bs(l,r,arr);
    }
};