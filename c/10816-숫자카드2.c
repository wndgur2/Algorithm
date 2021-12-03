#include <stdio.h>
#include <stdlib.h>
//mergeSort 후 binaryCount
void merge(int arr[], int l, int m, int r);
int binarySearch(int x, int *xS, int st, int end);
int binarySearchLength(int x, int *xS, int st, int end, int direction);

int main(){
  int n, m, i, f;
  scanf("%d", &n);
  int arr[n];

  for(i=0; i<n; i++)
    scanf("%d", &arr[i]);

	merge(arr, 0, (n-1)/2, n-1);

  scanf("%d", &m);

  for(i=0; i<m; i++){
    scanf("%d", &f);
    printf("%d ", binarySearch(f, arr, 0, n-1));
  }
  printf("\n");

	return 0;
}

int binarySearch(int x, int *xS, int st, int end){ //재귀호출보단 while문으로. st, end를 변화 주면서. 찾았을 때만 재귀.
  if(end - st < 0) return 0;

  while (end-st >= 0){
    int mid = (end+st)/2;
    if(xS[mid]==x) // 찾았을 때 시작과 끝 찾아서 그 길이 리턴.
      return binarySearchLength(x, xS, mid+1, end, 1) - binarySearchLength(x, xS, st, mid-1, 0) + 1;
    else if(xS[mid] < x)
      st = mid+1;
    else
      end = mid-1;
  }
  return 0;
}

int binarySearchLength(int x, int *xS, int st, int end, int direction){ //direction:0 = left, 1 = right
  int mid;
  if(direction){
    while (xS[st] == x){
      mid = (st+end)/2;
      if(xS[mid] == x) st = mid+1;
      else end = mid-1;
    }
    // printf("%d: right: %d\n", x, st-1);
    return st-1;
  } else{
    while (xS[end] == x){
      mid = (st+end)/2;
      if(xS[mid] != x) st = mid+1;
      else end = mid-1;
    }
    // printf("%d: left: %d\n", x, end+1);
    return end+1;
  }
  
  return 0;
}

void merge(int arr[], int l, int m, int r){
	if (l < r) {
		int m = l + (r - l) / 2;

		merge(arr, l, (l+m)/2, m);
		merge(arr, m + 1, (m+1+r)/2, r);
	}
  else return;
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[(l + i)];
	for (j = 0; j < n2; j++)
		R[j] = arr[(m + 1 + j)];

	i = 0;
	j = 0;
	k = l;
	while (i < n1 && j < n2) {
		if (L[i] < R[j]) {
			arr[k] = L[i];
			i++;
		} else{
      arr[k] = R[j];
      j++;
    }
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}