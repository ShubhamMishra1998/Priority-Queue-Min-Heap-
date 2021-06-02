/*this code is contrbuted by shubham mishra
email-sm544735@gmail.com
*/

class PriorityQueue{
 typedef long long ll;
 private:
 ll MAXSIZE = 1000000;
 ll *heap;
 ll heapSize;
 //Constructor when size is known
 public:
 PriorityQueue(ll n){
  heapSize = 0;
  heap = new long long[n];
 }
// Initilize heapSize when size is not known in advance
 PriorityQueue(){
  heapSize = 0;
  heap = new long long[MAXSIZE];
 }
//This method is used it move elements up
 private:void preLocateUp(){
   ll i = heapSize - 1;
   while(i>0&&heap[i]<heap[(i-1)/2]){
    swap(heap[i], heap[(i - 1) / 2]);
    i = (i - 1) / 2;
   }

 }

 public:ll getSize(){
   return heapSize;
 }

 public:ll getTop(){
   return heap[0];
 }

 // Insert in Priority Queue;
 public:void insert(ll x){
   heap[heapSize] = x;
   heapSize++;
   //Heapify the heap array
   preLocateUp();
 }
 
 private:void preLocateDown(ll i){
   ll min = i;
   ll left = 2 * i + 1;
   ll right = 2 * i + 2;
   if(left<heapSize&&heap[left]<heap[min]){
    min = left;
   }
   if(right<heapSize&&heap[right]<heap[min]){
    min = right;
   }
   if(min!=i){
    swap(heap[i], heap[min]);
    preLocateDown(min);
   }
 }
//Remove and get top element
public:ll removeTop(){
  ll x = heap[0];
  swap(heap[0], heap[heapSize - 1]);
  heapSize--;
  //heapify the heap
  preLocateDown(0);
}

};