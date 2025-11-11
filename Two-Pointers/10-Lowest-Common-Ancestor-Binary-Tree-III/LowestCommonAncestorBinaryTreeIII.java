/**
 * Lowest Common Ancestor of a Binary Tree III - Two Pointers Approach
 * LeetCode: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/ (Premium)
 *
 * Time Complexity: O(h) where h is height
 * Space Complexity: O(1)
 */

import java.util.HashSet;
import java.util.Set;

class LowestCommonAncestorBinaryTreeIII {

    // Definition for a Node with parent pointer
    static class Node {
        public int val;
        public Node left;
        public Node right;
        public Node parent;

        public Node(int val) {
            this.val = val;
        }
    }

    // Approach 1: Two Pointers - Path Intersection (Optimal)
    public Node lowestCommonAncestor(Node p, Node q) {
        Node p1 = p;
        Node p2 = q;

        // Move both pointers up until they meet
        while (p1 != p2) {
            // Move p1 up, or redirect to q if reached root
            p1 = (p1.parent != null) ? p1.parent : q;

            // Move p2 up, or redirect to p if reached root
            p2 = (p2.parent != null) ? p2.parent : p;
        }

        return p1; // or p2, they're equal
    }

    // Approach 2: Using HashSet
    // Time: O(h), Space: O(h)
    public Node lowestCommonAncestor2(Node p, Node q) {
        Set<Node> ancestors = new HashSet<>();

        // Store all ancestors of p
        Node current = p;
        while (current != null) {
            ancestors.add(current);
            current = current.parent;
        }

        // Find first ancestor of q that's also ancestor of p
        current = q;
        while (current != null) {
            if (ancestors.contains(current)) {
                return current;
            }
            current = current.parent;
        }

        return null; // Should never reach here if inputs are valid
    }

    // Approach 3: Get Depth First
    // Time: O(h), Space: O(1)
    public Node lowestCommonAncestor3(Node p, Node q) {
        int depth1 = getDepth(p);
        int depth2 = getDepth(q);

        // Align both nodes to same depth
        while (depth1 > depth2) {
            p = p.parent;
            depth1--;
        }

        while (depth2 > depth1) {
            q = q.parent;
            depth2--;
        }

        // Move both up until they meet
        while (p != q) {
            p = p.parent;
            q = q.parent;
        }

        return p;
    }

    private int getDepth(Node node) {
        int depth = 0;
        while (node.parent != null) {
            depth++;
            node = node.parent;
        }
        return depth;
    }

    // Helper method to build a sample tree for testing
    public static Node buildSampleTree() {
        //        3
        //       / \
        //      5   1
        //     / \ / \
        //    6  2 0  8
        //      / \
        //     7   4

        Node root = new Node(3);
        Node node5 = new Node(5);
        Node node1 = new Node(1);
        Node node6 = new Node(6);
        Node node2 = new Node(2);
        Node node0 = new Node(0);
        Node node8 = new Node(8);
        Node node7 = new Node(7);
        Node node4 = new Node(4);

        root.left = node5;
        root.right = node1;
        node5.parent = root;
        node1.parent = root;

        node5.left = node6;
        node5.right = node2;
        node6.parent = node5;
        node2.parent = node5;

        node1.left = node0;
        node1.right = node8;
        node0.parent = node1;
        node8.parent = node1;

        node2.left = node7;
        node2.right = node4;
        node7.parent = node2;
        node4.parent = node2;

        return root;
    }

    // Test cases
    public static void main(String[] args) {
        LowestCommonAncestorBinaryTreeIII solution = new LowestCommonAncestorBinaryTreeIII();

        Node root = buildSampleTree();
        Node node5 = root.left;
        Node node1 = root.right;
        Node node6 = node5.left;
        Node node2 = node5.right;
        Node node4 = node2.right;

        // Test case 1: LCA(5, 1) = 3
        Node result1 = solution.lowestCommonAncestor(node5, node1);
        System.out.println("Test 1 - LCA(5, 1): " + result1.val); // 3

        // Test case 2: LCA(5, 4) = 5
        Node result2 = solution.lowestCommonAncestor(node5, node4);
        System.out.println("Test 2 - LCA(5, 4): " + result2.val); // 5

        // Test case 3: LCA(6, 2) = 5
        Node result3 = solution.lowestCommonAncestor(node6, node2);
        System.out.println("Test 3 - LCA(6, 2): " + result3.val); // 5

        // Test case 4: LCA(6, 4) = 5
        Node result4 = solution.lowestCommonAncestor(node6, node4);
        System.out.println("Test 4 - LCA(6, 4): " + result4.val); // 5
    }
}
