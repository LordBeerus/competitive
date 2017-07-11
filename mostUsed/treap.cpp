#define treap treapNode*
class treapNode {
public :
    int priority, dp, add; // dp-> key add-> lazy propogation
    treap left;
    treap right;
    treapNode(int dp) {
        this->priority = ((rand() << 15) | rand());
        this->dp = dp;
        this->add = 0;
        this->left = this->right = NULL;
    }
};
  void push(treap t) {
    int add = t->add;
    t->dp += add;
    if (t->right)
        t->right->add += add;
    if (t->left)
        t->left->add += add;
    t->add = 0;
}

  int findBegin(treap t) { //find first key represented by this treap
    push(t);
    if (!t->left)
        return t->dp;
    return findBegin(t->left);
}

 
    // right must have all keys > left by design
  void merge(treap&result, treap left, treap right) {
    if (!right) {
        result = left;
        return;
    }
    if (!left) {
        result = right;
        return;
    }
    if (left->priority > right->priority) {
        push(left);
        merge(left->right, left->right, right);
        result = left;
        return;
    }
    push(right);
    merge(right->left, left, right->left);
    result = right;
    return;
}

  void split(treap breakThis, int val, treap&L, treap&R) {
    if (!breakThis) {
        L = R = NULL;
        return;
    }
    push(breakThis);
    if (breakThis->dp >= val) {
        split(breakThis->left, val, L, breakThis->left);
        R = breakThis;
        return;
    }
    split(breakThis->right, val, breakThis->right, R);
    L = breakThis;

};
