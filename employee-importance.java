// leetcode 690

/*
// Definition for Employee.
class Employee {
    public int id;
    public int importance;
    public List<Integer> subordinates;
};
*/

class Solution {
    public int getImportance(List<Employee> employees, int id) {
        Map<Integer, Employee> mp = new HashMap<>();
        for(Employee emp : employees) {
            mp.put(emp.id, emp);
        }
        int ans = 0;
        Queue<Integer> q = new LinkedList<>();
        q.offer(id);
        while(!q.isEmpty()) {
            int currId = q.poll();
            Employee emp = mp.get(currId);

            ans = ans + emp.importance;
            for(int subId : emp.subordinates) {
                q.add(subId);
            }
        }
        return ans;
    }
}
