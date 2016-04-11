import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Iterator;
import java.util.Scanner;

public class RadarInstallation{

	public static void main(String[] args){
		Main main = new Main();
		main.radarInstallation();
	}
	
	private void radarInstallation(){
		Scanner in = new Scanner(System.in);
		int n = in.nextInt();
		int d = in.nextInt();
		boolean findSolution = true;
		int count = 0;
		PrintWriter out = new PrintWriter(System.out);
		while(n != 0 ){
			if(d < 0){
				findSolution = false;
			}
			else{
				findSolution = true;
			}
			
			Section[] islandSections = new Section[n];
			
			int x,y;
			for(int i = 0; i < n;i++){
				x = in.nextInt();
				y = in.nextInt();
				if(findSolution == false){
					continue;
				}
				else{
					Section section = getIslandSection(x,y,d);
					if(section == null){
						findSolution = false;
					}
					else{
						islandSections[i] = section;
					}
				}
				
			}
			int raderCount = 1;
			if(findSolution == true){
				Arrays.sort(islandSections);
				double radarX = 0;
				if(islandSections.length> 0 ){
					Section pre = islandSections[0];
					radarX = pre.right;
					for(int i = 1;i < islandSections.length;i++){
						Section cur = islandSections[i];
						if(cur.left <= radarX ){
							if( radarX > cur.right){
								radarX = cur.right;
							}
						}
						else{
							radarX = cur.right;
							raderCount++;
						}
					}

				}
				
			}			
			else{
				raderCount = -1;
			}
			out.format("Case %d: %d\n", ++count, raderCount);
			n = in.nextInt();
			d = in.nextInt();

		}
		out.flush();
		

	}
	
	private Section getIslandSection(int x,int y,int d){
		Section section = new Section();
		double temp = d * d - y * y;
		if(temp >= 0){
			double deviation = Math.sqrt(temp);
			section.left =  x - deviation;
			section.right =  x + deviation;
			return section;
		}
		else{
			return null;
		}
		
	}
	
}
class Section implements Comparable<Section>{
	double left;
	double right;

	@Override
	public int compareTo(Section o) {
		if(this.left == o.left){
			return ((Double)this.right).compareTo((Double) o.right);
		}
		else{
			return ((Double)this.left).compareTo((Double) o.left);
		}
	}

	@Override
	public String toString() {
		return "Section [left=" + left + ", right=" + right + "]";
	}
	
}