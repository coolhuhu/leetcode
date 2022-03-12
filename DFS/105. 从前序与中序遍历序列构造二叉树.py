#!/usr/bin/env python
# -*- coding: UTF-8 -*-
"""
@Project ：pycharmCode 
@File    ：105. 从前序与中序遍历序列构造二叉树.py
@Author  ：lianghu
@Date    ：2022/3/10 22:21 
"""


# Definition for a binary tree node.
from typing import List


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        preLen = len(preorder)
        inLen = len(inorder)

        record = dict()
        for i in range(inLen):
            record[inorder[i]] = i

        def build(preorder, record, preLeft, preRight, inLeft, inRight):
            if preLeft < preRight or inLeft < inRight:
                return None
            rootVal = preorder[preLeft]
            rootIndex = record[rootVal]
            node = TreeNode(rootVal)
            node.left = build(preorder, record, preLeft + 1, rootIndex - inLeft + preLeft, inLeft, rootIndex - 1)
            node.right = build(preorder, record, preRight - inRight + rootIndex + 1, preRight, rootIndex + 1, inRight)
            return node



        return build(preorder, record, 0, preLen - 1, 0, inLen - 1)



