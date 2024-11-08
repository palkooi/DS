#include<stdio.h>
#include<stdlib.h>
void main(){
    int n,i,j=1,n1,n2,flag;
    printf("Enter the limit: ");
    scanf("%d",&n);
    int a[n];
    int b[n];
    
    for(i=0;i<n;i++){
        a[i]=j;
        j++;
        
    }
    
    printf("Set= {");

    for(i=0;i<n;i++){
        printf(" %d,",a[i]);
    }
    printf("}\n");
    
    for(i=0;i<n;i++){
        b[i]=1;
    }
    
    printf("Binary Eq= {");

    for(i=0;i<n;i++){
        printf(" %d,",b[i]);
    }
    printf("}\n");
    
    printf("Enter the first subset limit: ");
    scanf("%d",&n1);
    int a1[n1];
    int b1[n];
    printf("Enter the substring elements: ");
    for(i=0;i<n1;i++){
        scanf("%d",&a1[i]);
    }
    printf("A= {");

    for(i=0;i<n1;i++){
        printf(" %d,",a1[i]);
    }
    printf("}\n");
    
    
    
    int k=1;
    for(i=0;i<n;i++,k++){
        flag=0;
        for(j=0;j<n1;j++){
            if(k==a1[j]){
                b1[i]=1;
                flag=1;
            }
        }
        if(flag==0){
            b1[i]=0;
        }
    }
    
    printf("Binary Eq= {");
    for(i=0;i<n;i++){
        printf(" %d,",b1[i]);
    }
    printf("}\n");
    
    
    printf("Enter the second subset limit: ");
    scanf("%d",&n2);
    int a2[n2];
    int b2[n];
    printf("Enter the substring elements: ");
    for(i=0;i<n2;i++){
        scanf("%d",&a2[i]);
    }
    printf("B= {");

    for(i=0;i<n2;i++){
        printf(" %d,",a2[i]);
    }
    printf("}\n");
    
    
    
    k=1;
    for(i=0;i<n;i++,k++){
        flag=0;
        for(j=0;j<n2;j++){
            if(k==a2[j]){
                b2[i]=1;
                flag=1;
            }
        }
        if(flag==0){
            b2[i]=0;
        }
    }
    
    printf("Binary Eq= {");
    for(i=0;i<n;i++){
        printf(" %d,",b2[i]);
    }
    printf("}\n");
	    
    int uni[n];
    for(i=0;i<n;i++){
    	if(b1[i]==1 || b2[i]==1){
    		uni[i]=1;
    	}else{
		uni[i]=0;
	}
    }
    
    printf("union bit= {");
    for(i=0;i<n;i++){
        printf(" %d,",uni[i]);
    }
    printf("}\n");
    
    printf("union= {");
    for(i=0;i<n;i++){
    	if(uni[i]==1){
		printf(" %d,",i+1);
	}
    }
    printf("}\n");
    
    
    int itr[n];
    for(i=0;i<n;i++){
    	if(b1[i]==1 && b2[i]==1){
    		itr[i]=1;
    	}else{
		itr[i]=0;
	}
    }
    
    printf("intersection bit= {");
    for(i=0;i<n;i++){
        printf(" %d,",itr[i]);
    }
    printf("}\n");
    
    printf("intersection= {");
    for(i=0;i<n;i++){
    	if(itr[i]==1){
		printf(" %d,",i+1);
	}
    }
    printf("}\n");
    
    
    
    
}
