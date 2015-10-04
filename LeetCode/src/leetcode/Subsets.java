public class Subsets {
    public List<List<Integer>> subsets(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> result = new LinkedList<List<Integer>>();
        result.add(new LinkedList<Integer>());
        for(int i = 0;i < nums.length;i++){
            List<List<Integer>> newResult = new LinkedList<List<Integer>>();
            for(List row : result){
                List<Integer> newRow = new LinkedList<Integer>();
                newRow.addAll(row);
                newRow.add(nums[i]);
                newResult.add(newRow);
            }
            result.addAll(newResult);
        }
        return result;
        
    }
}