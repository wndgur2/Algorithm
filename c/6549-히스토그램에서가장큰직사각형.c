#include<stdio.h>
#include<stdlib.h>

int main(){
  int n, bef, t, i, j, k, idx, tdx;
  long long res, tempSize;
  int *sizes;
  while(1){
    scanf("%d", &n);
    if(n==0) break;
    
    res = 0; tempSize = 0; bef = 0; idx = 0;
    sizes = malloc(sizeof(int)*n*3);
    
    for(i=0; i<n; i++){
      scanf("%d", &t);
      
      for(j=0; j<idx/2; j++){ // 스택에 있던 t보다 작거나 같은 원소들 개수(너비) ++;
        if(sizes[j*2] <= t)
          sizes[j*2+1] ++;
        else{
          tdx = idx;
          idx -= (bef-t)*2;
          for(k=idx; k<tdx; k++){
            tempSize = (long long)sizes[k*2]*sizes[k*2+1]; // 스택의 원소가 t보다 크면 지금까지 최대 넓이 리턴, res보다 크면 res 대체. idx 조정
            if(tempSize > res)
              res = tempSize;
          }
        }
      }

      if(t>bef){
        for(j=bef; j<t; j++){ // bef부터 t까지의 높이들 스택에 추가
          sizes[idx] = j+1;
          sizes[idx+1] = 1;
          idx += 2;
        }
      }
      bef = t;
    }

    for(i=0; i<idx/2; i++){ // 스택의 남은 원소 중 res보다 큰 너비가 있는지 확인
      tempSize = sizes[i*2] * sizes[i*2+1]; // 스택의 원소가 t보다 크면 지금까지 최대 넓이 리턴, res보다 크면 res 대체
      if(tempSize > res){
        res = tempSize;
      }
    }

    printf("%lld\n", res);
    free(sizes);
  }

  return 0;
}