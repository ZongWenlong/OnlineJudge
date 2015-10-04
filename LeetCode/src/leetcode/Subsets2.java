public class Subsets2 {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        LinkedList<List<Integer>> result = new LinkedList<List<Integer>>();
        result.add(new LinkedList<Integer>());
        if(nums.length > 0){
            List<Integer> tempRow = new LinkedList<Integer>();
            tempRow.add(nums[0]);
            result.add(tempRow);
            
            int flag = 1;
            Iterator iter = result.listIterator(flag);
            for(int i = 1;i < nums.length;i++){
                if(nums[i] == nums[i - 1]){
                    iter = result.listIterator(flag);
                    flag = result.size();
                    List<List<Integer>> newResult = new LinkedList<List<Integer>>();
                    while(iter.hasNext()){
                        List<Integer> newRow = new LinkedList<Integer>();
                        newRow.addAll((List<Integer>)iter.next());
                        newRow.add(nums[i]);
                        newResult.add(newRow);
                    }
                    result.addAll(newResult);
                }
                else{
                    flag = result.size();
                    List<List<Integer>> newResult = new LinkedList<List<Integer>>();
                    for(List row : result){
                        List<Integer> newRow = new LinkedList<Integer>();
                        newRow.addAll(row);
                        newRow.add(nums[i]);
                        newResult.add(newRow);
                    }
                    result.addAll(newResult);
                }
                
            }
        }
        
        return result;
    }
}