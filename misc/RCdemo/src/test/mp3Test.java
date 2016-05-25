/** mp3 *******************************************************
 * Runs a web driver based test on github
 * Views the raw mp3.h file in the code_sample repo
 * 
 * Created on May 24, 2016
 * (c) Copyright IBM Corporation 2016
 * 
 *************************************************************/

package test;

import java.util.concurrent.TimeUnit;

import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import org.openqa.selenium.By;
import org.openqa.selenium.WebDriver;
import org.openqa.selenium.firefox.FirefoxDriver;

/**
 * Runs a web driver based test on github. <br>
 * Views the raw mp3.h file in the code_sample repo.
 * 
 * @author ronny <br>
 *         <img src=
 *         "http://beaveronthebeats.com/wp-content/uploads/2013/09/MP3-Symbol-Beaver-on-the-Beats.jpg"
 *         height=200 width=200>
 * 
 */
public class mp3Test {

	/**
	 * driver to access firefox
	 */
	public WebDriver driver;

	@Before
	public void setUp() throws Exception {
		driver = new FirefoxDriver();
		System.out.println("setup done");
	}

	@Test
	public void testMp3() throws Exception {

		// Puts an Implicit wait, Will wait for 10 seconds before throwing
		// exception
		driver.manage().timeouts().implicitlyWait(10, TimeUnit.SECONDS);

		// Launch website
		driver.navigate().to("http://www.calculator.net/");

		// Maximize the browser
		driver.manage().window().maximize();
		


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

	@After
	public void tearDown() throws Exception {
		System.err.println("Done!");
	}
}
