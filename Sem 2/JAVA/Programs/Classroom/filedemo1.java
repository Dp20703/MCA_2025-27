import java.io.File;
import java.io.*;
public class filedemo1
{
	public static void main(String args[])
		{
			try {
				File f1 = new File("kdj.txt");
			System.out.println(f1.createNewFile());
			}
			catch (IOException e)
			{
			System.out.println("file Not Found");
			}
			

		}
}