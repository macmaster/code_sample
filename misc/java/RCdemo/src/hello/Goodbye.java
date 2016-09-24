/**
 * 
 */
package hello;

import java.util.concurrent.TimeUnit;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

/**
 * @author ronny
 *
 */
public class Goodbye {

	public static void main(String[] args) {
		
		//firefox web driver
		WebDriver driver = new FirefoxDriver();
		try{
			Thread.sleep(10000);
			System.out.println("went to website!");
		} catch(Exception e){
			e.printStackTrace();
			System.out.println("please allow the driver to load up longer");
		}
		
		// Launch website
		driver.navigate().to("http://www.calculator.net/");
		
		
		// Puts an Implicit wait, Will wait for 10 seconds before throwing exception
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);

		System.out.println("set the timeout!");

		// Maximize the browser
		driver.manage().window().maximize();
		
		System.out.println("maxed the window!");

		// Click on Math Calculators
		driver.findElement(By.xpath(".//*[@id='menu']/div[3]/a")).click();

		// Click on Percent Calculators
		driver.findElement(By.xpath(".//*[@id='menu']/div[4]/div[3]/a"))
				.click();

		// Enter value 10 in the first number of the percent Calculator
		driver.findElement(By.id("cpar1")).sendKeys("10");

		// Enter value 50 in the second number of the percent Calculator
		driver.findElement(By.id("cpar2")).sendKeys("50");

		// Click Calculate Button
		driver.findElement(
				By.xpath(".//*[@id='content']/table/tbody/tr[2]/td/input[2]"))
				.click();

		// Get the Result Text based on its xpath
		String result = driver.findElement(
				By.xpath(".//*[@id='content']/p[2]/font/b")).getText();

		// Print a Log In message to the screen
		System.out.println(" The Result is " + result);

		// Close the Browser.
		driver.close();
	}

	public void sayGoodbye() {
		System.out.println("Say goodbye bro!");
	}

}
