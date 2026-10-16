struct ListNode* reverse(struct ListNode* head) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;

    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int pairSum(struct ListNode* head) {
    struct ListNode *slow = head;
    struct ListNode *fast = head;

    // Find middle
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse second half
    struct ListNode* second = reverse(slow);

    int maxSum = 0;

    // Calculate twin sums
    while (second) {
        int sum = head->val + second->val;

        if (sum > maxSum)
            maxSum = sum;

        head = head->next;
        second = second->next;
    }

    return maxSum;
}