void buildBST(int N, char n[], BST *root, BST *pt)
{
    BST *NEW;
    if (N <= 0)
        return;
    if (n[0] > pt->key)
        if (pt->dx != NULL)
            buildBST(N, n, root, pt->dx);
        else
        {
            NEW = (BST *)malloc(sizeof(BST));
            NEW->dx = NEW->sx = NULL;
            NEW->key = n[0];
            pt->dx = NEW;
            buildBST(N - 1, n + 1, root, root);
        }
    else /* a[0] <= pt->key */
        if (pt->sx != NULL)
            buildBST(N, n, root, pt->sx);
        else
        {
            NEW = (BST *)malloc(sizeof(BST));
            NEW->dx = NEW->sx = NULL;
            NEW->key = n[0];
            pt->sx = NEW;
            buildBST(N - 1, n + 1, root, root);
        }
}