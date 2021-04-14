#define MAXSIZE 10
typedef struct 
{
    int r[MAXSIZE+1];
    int length;
} SqList;

void swap(SqList *L,int i,int j)
{
    int temp = L->r[i];
    L->r[i] = L->r[j];
    L->r[j] = temp;
}

void BubbleSort(SqList *L)
{
    bool flag = true;
    for (int i = 1; i < L->length && flag; i++)
    {
        flag = false;
        for (int j = L->length-1; j >=1; j--)
        {
            if ((L->r[j]>L->r[j+1]))
            {
                swap(L,j+1,j);
                flag = true;
            }
            
        }
        
    }
    
}

void SelectSort(SqList *L)
{
    int min, i, j, k;
    
    for ( i = 1; i < L->length; i++)
    {
        min = i;
        for (j = i+1; j < L->length; j++)
        {
            if (L->r[min]>L->r[j])
            {
                min = j;
            }
        } 
        if (i!=min)
        {
            swap(L, i, min);
        }  
    }
}
void InsertSort(SqList *L)
{
    int i, j, k;
    for ( i = 2; i < L->length; i++)
    {
        
        if (L->r[i]<L->r[i-1])
        {
            L->r[0] = L->r[i];
            
            for ( k = i-1; L->r[k]>L->r[0]; k--)
            {
                L->r[k + 1] = L->r[k];
            }
            L->r[k+1] = L->r[0];
        } 
    }
}

void shellSort(SqList *L)
{
    int i, j;
    int increment = L->length;
    do
    {
        increment = increment / 3 + 1;
        for ( i = increment+1; i <= L->length; i++)
        {
            if (L->r[i]<L->r[i-increment])
            {
                L->r[0] = L->r[i];
                for ( j = i-increment; L->r[j]>L->r[0]; i++)
                {
                    L->r[j+increment] = L->r[j];
                    /* code */
                }
                L->r[j] = L->r[0];
            }
            
        }
        
    } while (increment>1);
}

void HeapAdjust(SqList *L,int s,int m)
{
    int temp, j;
    temp = L->r[s];
    for (j = s*2; j <= m; j*=2)
    {
        if(j<m && L->r[j]<L->r[j+1])
        {
            ++j;
        }
        if (temp >= L->r[j])
        {
            break;
            /* code */
        }
        L->r[s] = L->r[j];
        s = j;
        L->r[s] = temp;
    }
}

void HeapSort(SqList * L)
{
    int i;
    for ( i = L->length/2; i < L->length; i--)
    {
        HeapAdjust(L, i, L->length);
    }
    for ( i = L->length; i > 1; i--)
    {
        swap(L, i, 1);
        HeapAdjust(L, 1, i-1);
    }
}
void Merge(int SR[],int TR[],int i,int m,int n)
{
    int j, k, l;
    for ( j = m+1,k=i; i <= m && j<=n; k++)
    {
        if (SR[i]<SR[j])
        {
            TR[k] = SR[i++];
            /* code */
        }else
        {
            TR[k] = SR[j++];
        } 
    }
    if (i<=m)
    {
        for ( l = 0; l < m-i; l++)
        {
            TR[k + l] = SR[i + l];
        }
    }
    if (j<=n)
    {
        for ( l = 0; l < n-j; l++)
        {
            TR[k + l] = SR[j + l];
        }
        



        /* code */
    }
    
}
void MSort(int SR[],int TR1[],int s,int t)
{
    int m;
    int TR2[MAXSIZE + 1];
    if (s==t)
    {
        TR1[s] = SR[s];
        /* code */
    }else
    {
        m = (s + t) / 2;
        MSort(SR, TR2, s, m);
        MSort(SR, TR2, m+1, t);
        Merge(TR2,TR1,s,m,t);
    }
    
    

}
int Partition(SqList *L,int low,int high)
{
    int pivotkey;
    pivotkey = L->r[low];
    while (low<high)
    {
        while (low<high&&L->r[high]>=pivotkey)
        {
            high--;
            /* code */
        }
        swap(L, low, high);
        while (low<high&&L->r[low]<=pivotkey)
        {
            low++;
            /* code */
        }
        swap(L, low, high);


        /* code */
    }
    return low;
}

void QSort(SqList *L,int low,int high)
{
    int pivot;
    if (low<high)
    {
        pivot = Partition(L, low, high);
        QSort(L, low, pivot - 1);
        QSort(L, pivot + 1, high);
        /* code */
    }
    
}
void MergeSort(SqList *L)
{
    MSort(L->r, L->r, 1,L->length);
}
void QuickSort(SqList * L)
{
    QSort(L, 1, L->length);
}


