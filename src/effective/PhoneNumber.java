package effective;

public class PhoneNumber {
	private short areaCode;
	private short prefix;
	public PhoneNumber(short areaCode, short prefix) {
		super();
		this.areaCode = areaCode;
		this.prefix = prefix;
	}
	
	@Override
	public boolean equals(Object o){
		if(o == this){
			return true;
		}
		if(!(o instanceof PhoneNumber)){
			return false;
		}
		
		PhoneNumber pn = (PhoneNumber) o;
		return pn.areaCode == this.areaCode &&
				pn.prefix == this.prefix;
	}
	
	//—”≥Ÿ≥ı ºªØ
	private volatile int hashCode;
	@Override
	public int hashCode(){
		int result= hashCode;
		if(result == 0){
			result = 17;
			result = 31 * result + areaCode;
			result = 31 * result + prefix;
			hashCode = result;
		}
		return result;
	}
}
