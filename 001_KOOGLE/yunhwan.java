import java.util.Arrays;
import java.util.Scanner;
import java.lang.Math;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		
		//케이스 
		int numberOfCase = sc.nextInt(); 
		for (int i =0; i< numberOfCase; i++){ 
			
			double power =0;
			String code ="";
	    	
		//암호 후보
	    	int numberOfCode = sc.nextInt();     	
	    	for ( int j=0; j< numberOfCode; j++){ 
	    		
	    		int num1 = 0;
	    	
	    		//강도 구하기
	    		String cur_code = sc.next();		
	    		double cur_power = 0;
	    		
	    		for ( int k=0; k<cur_code.length(); k++ ){
	    			if ( Character.isLowerCase( cur_code.charAt(k) ))
	    			{
	    				cur_power += Math.log10(26);
	    			}
	    			else { cur_power += 1; }
	    		}
	    		//비교 
	    		if ( power < cur_power ){
	    			power = cur_power;
	    			code = cur_code;
	    		} 
	    		else if (power == cur_power) {
	    			if (code.compareTo(cur_code)>0){
	    				code = cur_code;}		            
	    		}	    		
	    	}
	    	System.out.println(code);
	    }
	 sc.close();
	}
}
