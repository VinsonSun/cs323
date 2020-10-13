#include "symtab.h"

/*
 * symbol table type, binary tree impl
 */
struct symtab {
    entry entry;
    struct symtab *left, *right;
};

// ************************************************************
//    Your implementation goes here
// ************************************************************

symtab *symtab_init(){
    symtab *self = malloc(sizeof(symtab));
    memset(self, '\0', sizeof(symtab));
    self->left = NULL;
    self->right = NULL;
    return self;
}

int symtab_insert(symtab *self, char *key, VAL_T value){
        symtab *parent;   //表示双亲结点；
	symtab *head = self;
	symtab *p=(symtab *)malloc(sizeof(symtab));
	strcmp(p->entry.key, key);   //保存结点数据；
        p->entry.value = value;
	p->left=p->right=NULL;  //左右子树置空；
	
	//查找需要添加的父结点，这个父结点是度为0的结点；
	while(head) 
	{
		parent=head;
		if(value<head->entry.value)   //若关键字小于结点的数据；
			head=head->left; //在左子树上查找； 
		else   //若关键字大于结点的数据；
			head=head->right;  //在右子树上查找；
	}
	//判断添加到左子树还是右子树；
	if(value<parent->entry.value)   //小于父结点；
		parent->left=p;    //添加到左子树；
	else    //大于父结点；
		parent->right=p;   //添加到右子树；
}

VAL_T symtab_lookup(symtab *self, char *key){

}

int symtab_remove(symtab *self, char *key){

}
