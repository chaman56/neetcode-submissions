struct Node{
    char ch;
    vector<Node*>child;
    bool end = false;
    Node(){
        child.resize(26, nullptr);
    }
    Node(char c){
        ch = c;
        child.resize(26, nullptr);
    }
};

class PrefixTree {
    Node* root = new Node();
public:
    PrefixTree() { }
    
    void insert(string word) {
        int sz = word.size();
        Node* temp = root;
        for(int i = 0; i<sz; i++){
            int j = word[i]-'a';
            if(!temp->child[j])temp->child[j] = new Node(word[i]);
            temp = temp->child[j];
        }
        temp->end = true;
    }
    
    bool search(string word) {
        int sz = word.size();
        Node* temp = root;
        for(int i = 0; i<sz; i++){
            int j = word[i]-'a';
            if(!temp->child[j])return false;
            temp = temp->child[j];
        }
        return temp->end;
    }
    
    bool startsWith(string prefix) {
        int sz = prefix.size();
        Node* temp = root;
        for(int i = 0; i<sz; i++){
            int j = prefix[i]-'a';
            if(!temp->child[j])return false;
            temp = temp->child[j];
        }
        return true;
    }
};
