/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Void. Just modifies the args passed by reference 
 */
void arrange(int* arr, int n1) {
    int i;
    for(i=0;i<n1;i++)
    {
        arr[i]=(arr[i]+((arr[arr[i]])%n1)*n1);
    }
    for(i=0;i<n1;i++)
    {
        arr[i]=arr[i]/n1;
    }
}
