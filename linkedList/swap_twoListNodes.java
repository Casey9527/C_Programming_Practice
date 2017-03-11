/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    /**
     * @param head a ListNode
     * @oaram v1 an integer
     * @param v2 an integer
     * @return a new head of singly-linked list
     */
    public ListNode swapNodes(ListNode head, int v1, int v2) {
        // Write your code here
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        
        ListNode p1 = getPreviousNode(dummy, v1);
        ListNode p2 = getPreviousNode(dummy, v2);
        
        if (p1 == null || p2 == null || p1 == p2) {
            return head;
        }
        
        ListNode n1 = p1.next;
        ListNode n2 = p2.next;
        
        ListNode tmp = n2.next;
        
        
        p1.next = n2;
        
        if (n1.next != n2) {
            n2.next = n1.next;   
        } else {
            n2.next = n1;
        }
        
        n1.next = tmp; // n2.next;

        
        if (p2 != n1) {
            p2.next = n1;
        }
        return dummy.next;
    }
    
    // dummy -> 1 -> 2 -> 3 -> 4 -> null
    private ListNode getPreviousNode (ListNode head, int v) {
        if (head == null) {
            return null;
        }
        while (head.next != null) {
            if (head.next.val == v) {
                return head;
            }
            head = head.next;
        }
        return null;
    }
}



/*
testcases
null



1->null

1->2->null




1->2->3->4->null
    1). 1 2  相邻且有一个为首
        1 3  不相邻且有一个为首
        3 4  相邻且有一个为尾
        2 4  不相邻且有一个为尾
    
    2). 1 3  不相邻一般情况
    3). 5 6  两个都不在里面
    4). 1 5  有一个在里面
    5). 


*/