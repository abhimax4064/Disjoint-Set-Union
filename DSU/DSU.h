class UnionFind{
   int n;
   vector<int> parent, size;
public:
   
   //Constructs a Disjoint Set Union with n elements
   UnionFind(int n){
      this->n=n;
      parent = vector<int>(n);
      size = vector<int>(n,1);
      
      for(int i=0; i<n; i++){
         parent[i]=i;
      }
   }
   
   //finds the parent of the given of the given element 
   int find(int x){
      if(parent[x] == x){
         return x;
      }
      return parent[x] = find(parent[x]);
   }
   
   //binds two elements in to a single component by using rank(size)
   void Union(int u, int v){
      int p1 = find(u);
      int p2 = find(v);

      if(p1 != p2){
         if(size[p1]>size[p2]){
            parent[p2]=p1;
            size[p1]+=size[p2];
         }
         else{
            parent[p1]=p2;
            size[p2]+=size[p1];
         }
      }
   }
   
   //returns the size of the component to which the element u belongs
   int get_size(int u){
      int p = find(u);
      return size[p];
   }

   //returns the maximum size of a component
   int max_size(){
      int mx = -inf;
      for(auto &x: size){
         mx = max(mx, x);
      }
      return mx;
   } 
};
