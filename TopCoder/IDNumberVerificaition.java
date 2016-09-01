import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.TreeSet;


public class IDNumberVerificaition {


	public static void main(String[]args)throws Throwable
	{
		
		System.out.println(9^3);
		System.out.println(Math.log(256));
		String s = "350823194634020182";
		String x[] = {"350823"};
		System.out.println(verify(s,x));
	}

	public static String verify(String id,String[] arr)
	{




		String code = id.substring(0, 6);
		boolean found = false;
		for(String c : arr) found |= c.equals(code);

		if(!found) return "Invalid";
		long mychecksum = 0;

		for(int i = 0; i < id.length() - 1; i++) mychecksum += (((((1L << (18-(i+1)))%11) * (id.charAt(i) -'0')))%11);

		char checksum = id.charAt(17);

		int x = checksum == 'X' ? 10 : checksum -'0';


		mychecksum %= 11;
		
		if( ((x+mychecksum)%11) != 1 ) {
			return "Invalid";
		}

		String year = id.substring(6, 10);

		String month = id.substring(10, 12);

		String day = id.substring(12,14);

		String seqCode = id.substring(14, 17);

		if(seqCode.equals("000")) return "Invalid";

		int gender = Integer.parseInt(seqCode);

		DateFormat dateFormat = new SimpleDateFormat("yyyy-MM-dd");

		dateFormat.setLenient(false);



		if(Integer.parseInt(year) > 2011 || Integer.parseInt(year) < 1900) return "Invalid";

		String dateAsString = year+"-"+month+"-"+day;

		try{
			Date date = dateFormat.parse(dateAsString);  
		}
		catch(Exception e)
		{

			return "Invalid";
		}
		return gender % 2 == 1 ? "Male" : "Female";

	}
}
