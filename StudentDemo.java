import java.util.*;
class Student
{
	String usn,name;
	int credits[];
	int marks[];
	int i,j,n;
	float sgpa;
	int total;
	int k=0;
	void set()
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("enter usn,name=");
		usn=sc.next();
		name=sc.next();
		System.out.println("enter no of subjects=");
		n=sc.nextInt();
		credits=new int[n];
		marks=new int[n];
		System.out.println("enter the credits=");
		for(i=0;i<n;i++)
		{
			credits[i]=sc.nextInt();
		}
		System.out.println("enter the marks of subjects=");
		for(j=0;j<n;j++)
		{
			marks[j]=sc.nextInt();
		}
	}
	void compute()
	{
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				 int m=marks[j];
				if(m>=90)
				{
					k+=10*credits[i];
				}	
				else if(m<90&&m>=70)
				{
					k+=9*credits[i];
				}
				else if(m<70&&m>=60)
				{
					k+=8*credits[i];
				}
				else if(m<60&&m>=50)
				{
					k+=7*credits[i];
				}
				else if(m<50&&m>=40)
				{
					k+=6*credits[i];
				}
				else
				{
					
					k+=0;
				}
		
		
			}
		for(i=0;i<n;i++)
		{
			total+=credits[i];
		}
		sgpa=k/total;

		}
	}
	void display()
	{
		System.out.println("sgpa="+sgpa);
	}
}
class StudentDemo
{
	public static void main(String args[])
	{
		Student ob=new Student();
		ob.set();
		ob.compute();
		ob.display();
	}
}
