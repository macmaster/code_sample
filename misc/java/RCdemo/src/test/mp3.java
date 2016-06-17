package test;

import java.util.regex.Pattern;
import java.util.concurrent.TimeUnit;
import org.junit.*;
import static org.junit.Assert.*;
import static org.hamcrest.CoreMatchers.*;
import org.openqa.selenium.*;
import org.openqa.selenium.firefox.FirefoxDriver;
import org.openqa.selenium.support.ui.Select;

public class mp3 {
  private WebDriver driver;
  private String baseUrl;
  private boolean acceptNextAlert = true;
  private StringBuffer verificationErrors = new StringBuffer();

  @Before
  public void setUp() throws Exception {
    driver = new FirefoxDriver();
    baseUrl = "https://github.com/ronny-macmaster";
    driver.manage().timeouts().implicitlyWait(30, TimeUnit.SECONDS);
  }

  @Test
  public void testMp3() throws Exception {
    driver.get(baseUrl + "/ronny-macmaster");
    driver.findElement(By.xpath("//div[@id='js-pjax-container']/div/div/div[2]/div[2]/div/div/div/div/ul/li[3]/a/span/span")).click();
    driver.findElement(By.id("0d61f8370cad1d412f80b84d143e1257-2a415e9f65782f1fb4f1bfad4585ef5629416ca9")).click();
    driver.findElement(By.id("a0f2eaa152ad6f1377047d2e994fdba7-17692e6793a3f23c6398e1856a2800859a49334c")).click();
    driver.findElement(By.id("2bb8b94473344d16a60a402829722222-6e132598e2dce6122b490de2d55ca326bee75546")).click();
    driver.findElement(By.id("raw-url")).click();
    assertTrue(driver.findElement(By.cssSelector("pre")).getText().matches("^exact:/[\\s\\S]* Frequencies jacked from Valvano and co\\.\n All songs are orignally coded by Ronny\n Music jacked from http://www\\.ninsheetmusic\\.org/ \n Notes are grouped by Respective Measures \n [\\s\\S]*/\n\n/[\\s\\S]* Note Frequencies [\\s\\S]*/\n#define C1 1194 /[\\s\\S]* 2093 Hz [\\s\\S]*/\n#define B1 1265 /[\\s\\S]* 1975\\.5 Hz [\\s\\S]*/\n#define BF1 1341 /[\\s\\S]* 1864\\.7 Hz [\\s\\S]*/\n#define A1 1420 /[\\s\\S]* 1760 Hz [\\s\\S]*/\n#define AF1 1505 /[\\s\\S]* 1661\\.2 Hz [\\s\\S]*/\n#define G1 1594 /[\\s\\S]* 1568 Hz [\\s\\S]*/\n#define GF1 1689 /[\\s\\S]* 1480 Hz [\\s\\S]*/\n#define F1 1790 /[\\s\\S]* 1396\\.9 Hz [\\s\\S]*/\n#define E1 1896 /[\\s\\S]* 1318\\.5 Hz [\\s\\S]*/\n#define EF1 2009 /[\\s\\S]* 1244\\.5 Hz [\\s\\S]*/\n#define D1 2128 /[\\s\\S]* 1174\\.7 Hz [\\s\\S]*/\n#define DF1 2255 /[\\s\\S]* 1108\\.7 Hz [\\s\\S]*/\n#define C 2389 /[\\s\\S]* 1046\\.5 Hz [\\s\\S]*/\n#define B 2531 /[\\s\\S]* 987\\.8 Hz [\\s\\S]*/\n#define BF 2681 /[\\s\\S]* 932\\.3 Hz [\\s\\S]*/\n#define A 2841 /[\\s\\S]* 880 Hz [\\s\\S]*/\n#define AF 3010 /[\\s\\S]* 830\\.6 Hz [\\s\\S]*/\n#define G 3189 /[\\s\\S]* 784 Hz [\\s\\S]*/\n#define GF 3378 /[\\s\\S]* 740 Hz [\\s\\S]*/\n#define F 3579 /[\\s\\S]* 698\\.5 Hz [\\s\\S]*/\n#define E 3792 /[\\s\\S]* 659\\.3 Hz [\\s\\S]*/\n#define EF 4018 /[\\s\\S]* 622\\.3 Hz [\\s\\S]*/\n#define D 4257 /[\\s\\S]* 587\\.3 Hz [\\s\\S]*/\n#define DF 4510 /[\\s\\S]* 554\\.4 Hz [\\s\\S]*/\n#define C0 4778 /[\\s\\S]* 523\\.3 Hz [\\s\\S]*/\n#define B0 5062 /[\\s\\S]* 493\\.9 Hz [\\s\\S]*/\n#define BF0 5363 /[\\s\\S]* 466\\.2 Hz [\\s\\S]*/\n#define A0 5682 /[\\s\\S]* 440 Hz [\\s\\S]*/\n#define AF0 6020 /[\\s\\S]* 415\\.3 Hz [\\s\\S]*/\n#define G0 6378 /[\\s\\S]* 392 Hz [\\s\\S]*/\n#define GF0 6757 /[\\s\\S]* 370 Hz [\\s\\S]*/\n#define F0 7159 /[\\s\\S]* 349\\.2 Hz [\\s\\S]*/\n#define E0 7584 /[\\s\\S]* 329\\.6 Hz [\\s\\S]*/\n#define EF0 8035 /[\\s\\S]* 311\\.1 Hz [\\s\\S]*/\n#define D0 8513 /[\\s\\S]* 293\\.7 Hz [\\s\\S]*/\n#define DF0 9019 /[\\s\\S]* 277\\.2 Hz [\\s\\S]*/\n#define C7 9556 /[\\s\\S]* 261\\.6 Hz [\\s\\S]*/\n#define B7 10200 /[\\s\\S]* 246\\.9 Hz [\\s\\S]*/ /[\\s\\S]*\\(Sounds a little sharp\\) [\\s\\S]*/\n#define BF7 10726 /[\\s\\S]* 233\\.1 Hz [\\s\\S]*/ /[\\s\\S]*\\(BE CAREFUL WITH THESE 2 [\\s\\S]*/\n#define A7 11364 /[\\s\\S]* 220 Hz [\\s\\S]*/\n#define AF7 12039 /[\\s\\S]* 207\\.7 Hz [\\s\\S]*/\n#define G7 12755 /[\\s\\S]* 196 Hz [\\s\\S]*/\n#define GF7 13514 /[\\s\\S]* 185 Hz [\\s\\S]*/\n#define F7 14317 /[\\s\\S]* 174\\.6 Hz [\\s\\S]*/\n#define E7 15169 /[\\s\\S]* 164\\.8 Hz [\\s\\S]*/\n#define EF7 16071 /[\\s\\S]* 155\\.6 Hz [\\s\\S]*/\n#define D7 17026 /[\\s\\S]* 146\\.8 Hz [\\s\\S]*/\n#define DF7 18039 /[\\s\\S]* 138\\.6 Hz [\\s\\S]*/\n#define C6 19111 /[\\s\\S]* 130\\.8 Hz [\\s\\S]*/\n\n/[\\s\\S]* LEGEND OF ZELDA TITLE THEME\n Sounds best at 144bpm eigth 120or144bpm 16th [\\s\\S]*/\n\n/[\\s\\S]* melody [\\s\\S]*/ \nconst unsigned long int Zelda_high\\[128\\] = \\{ \n \n A,D,BF0,G0,\n G,D,BF0,G0,\n GF,D,BF0,G0,\n G,D,BF0,G0,\n \n G,C0,A0,F0,\n F,C0,A0,F0,\n E,C0,A0,F0,\n F,C0,A0,F0,\n \n F,BF0,G0,E0,\n E,BF0,G0,E0,\n EF,BF0,G0,E0,\n E,BF0,G0,E0,\n\n E,A0,F0,D0,\n D,A0,F0,D0,\n DF,A0,F0,D0,\n D,A0,F0,D0,\n\n A,D,BF0,G0,\n G,D,BF0,G0,\n GF,D,BF0,G0,\n G,D,BF0,G0,\n \n BF,EF,C0,A0,\n A,EF,C0,A0,\n AF,EF,C0,A0,\n A,EF,C0,A0,\n\n C,D,BF0,G0,\n BF,D,BF0,G0,\n A,D,BF0,G0,\n BF,D,BF0,G0,\n \n A,BF0,G0,E0,\n G,BF0,G0,E0,\n F,BF0,G0,E0,\n E,BF0,G0,E0\n \n\\}; \n\n/[\\s\\S]* bass [\\s\\S]*/\nconst unsigned long int Zelda_low\\[128\\] = \\{ \n \n BF7,BF7,D0,A0,\n A0,A0,A0,A0,\n A0,D0,A0,G0,\n C0,A0,G0,D0,\n \n A7,A7,C7,G0,\n G0,G0,G0,G0,\n G0,A7,G0,F0,\n C0,A0,G0,C7,\n \n G7,G7,C7,F0,\n F0,F0,F0,F0,\n F0,G7,F0,E0,\n G0,E0,C7,C7,\n\n F7,F7,A7,E0,\n E0,E0,E0,E0,\n F7,C7,E0,D0,\n G0,F0,C7,BF7,\n\n BF7,BF7,D0,A0,\n A0,A0,A0,A0,\n BF7,D0,A0,G0,\n D,A0,G0,D0,\n \n A7,A7,C7,C0,\n C0,C0,C0,C0,\n D0,D0,C0,A0,\n EF,D,C0,A0,\n\n G7,BF7,D0,BF0,\n BF0,BF0,BF0,BF0,\n G0,D0,BF0,A0,\n C0,BF0,G0,D0,\n \n C7,C7,G0,BF0,\n BF0,BF0,BF0,BF0,\n C7,C7,BF0,G0,\n E,D,G,E\n \n\\}; \n\n\n/[\\s\\S]* Pokemon Center\n Sounds best with 120bm eighth notes[\\s\\S]*/\n\n/[\\s\\S]* melody [\\s\\S]*/\nconst unsigned long int PokemonCenter_high\\[128\\] = \\{ \n \n D,A0,D,A,\n A,G,G,GF,\n E,DF,0,0,\n A0,A0,G0,A0,\n \n DF,A0,DF,GF,\n GF,E,E,DF,\n D,GF,0,0,\n D,DF,B0,A0,\n \n D,A0,D,A,\n A,G,G,GF,\n E,DF,0,0,\n A0,A0,G0,A0,\n \n DF,A0,DF,GF,\n GF,E,E,DF,\n D,D,D,0,\n GF0,G0,A0,B0,\n\n GF,GF,GF,GF,\n A,A,0,0,\n G,A,G,GF,\n E,E,0,0,\n \n DF,DF,DF,0,\n E,E,0,0,\n GF,G,GF,E,\n D,D,D,0,\n\n GF,GF,GF,0,\n A,A,0,0,\n G,GF,G,A,\n B,B,0,0,\n \n \n A,A,G,GF,\n G,G,0,0,\n GF,G,GF,E,\n D,D,0,0\n \n\\}; \n\n/[\\s\\S]* Harmony [\\s\\S]*/\nconst unsigned long int PokemonCenter_middle\\[128\\] = \\{ \n \n GF0,F0,GF0,D,\n D,DF,B0,A0,\n B0,A0,G0,GF0,\n E0,GF0,E0,0,\n \n A0,E0,A0,DF,\n DF,B0,A0,G0,\n GF0,A0,B0,DF,\n A0,0,E0,0,\n \n GF0,F0,GF0,D,\n D,DF,B0,A0,\n B0,A0,G0,GF0,\n E0,GF0,E0,0,\n \n A0,E0,A0,DF,\n DF,B0,A0,G0,\n GF0,E0,D0,E0,\n D0,0,E0,0,\n\n GF0,E0,D0,0,\n E0,GF0,G0,A0,\n B0,A0,G0,0,\n E0,GF0,G0,A0,\n \n G0,GF0,E0,0,\n DF0,D0,E0,G0,\n GF0,G0,A0,B0,\n A0,A0,A0,0,\n\n D,DF,B0,0,\n A0,B0,DF,D,\n E,D,DF,0,\n B0,DF,D,E,\n \n \n DF,B0,A0,0,\n G0,A0,B0,G0,\n A0,G0,GF0,E0,\n D0,E0,GF0,G0\n \n\\}; \n\n/[\\s\\S]* Bass [\\s\\S]*/ \nconst unsigned long int PokemonCenter_low\\[128\\] = \\{ \n \n D7,GF7,D7,GF7,\n D7,GF7,G7,GF7,\n E7,A7,E7,A7,\n E7,A7,E7,A7,\n \n E7,A7,E7,A7,\n E7,A7,G7,A7,\n GF7,A7,GF7,A7,\n GF7,A7,G7,A7,\n \n D7,GF7,D7,GF7,\n D7,GF7,G7,GF7,\n E7,A7,E7,A7,\n E7,A7,E7,A7,\n \n E7,A7,E7,A7,\n E7,A7,G7,A7,\n D7,GF7,D7,GF7,\n D7,A7,G7,GF7,\n\n GF7,A7,GF7,A7,\n GF7,A7,GF7,A7,\n G7,B7,G7,B7,\n G7,B7,G7,B7,\n \n E7,G7,E7,G7,\n E7,G7,E7,G7,\n GF7,A7,GF7,A7,\n GF7,A7,GF7,A7,\n\n GF7,A7,GF7,A7,\n GF7,A7,GF7,A7,\n G7,B7,G7,B7,\n G7,B7,G7,B7,\n \n E7,G7,E7,G7,\n E7,G7,E7,G7,\n GF7,A7,GF7,A7,\n GF7,A7,GF7,A7,\n \n\\}; \n\n\n\n/[\\s\\S]* Cerulean City Theme\n 2 BARS OF INTRO, ENABLE INTRO CODE\n Sounds best with 120bpm 16th notes [\\s\\S]*/\n\nconst unsigned long int CeruleanCityIntro_high\\[32\\] = \\{ \n \n E,0,EF,0,\n DF,0,B0,0,\n A0,0,B0,0,\n DF,0,EF,0,\n \n E,E,0,0,\n 0,0,E,B0,\n DF,DF,EF,EF,\n E,GF,AF,A\n \n\\};\n\nconst unsigned long int CeruleanCityIntro_middle\\[32\\] = \\{ \n \n 0,0,0,0,\n 0,0,0,0,\n E0,0,EF0,0,\n DF0,0,C7,0,\n \n B7,B7,0,0,\n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0\n \n\\};\n\nconst unsigned long int CeruleanCityIntro_low\\[32\\] = \\{ \n \n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n \n E7,E7,AF7,AF7,\n E7,E7,AF7,AF7,\n E7,E7,AF7,AF7,\n E7,E7,AF7,AF7\n \n\\};\n \n\n/[\\s\\S]* The MEAT of the song [\\s\\S]*/\n/[\\s\\S]* melody [\\s\\S]*/\nconst unsigned long int CeruleanCity_high\\[256\\] = \\{ \n \n AF,AF,AF,AF,\n AF,AF,A,AF,\n GF,GF,GF,GF,\n GF,GF,0,0,\n \n 0,0,0,0,\n 0,0,E,B0,\n DF,DF,EF,EF,\n E,GF,AF,A,\n \n AF,AF,AF,AF,\n AF,AF,E,AF,\n B,B,B,B,\n B,B,0,0,\n \n 0,0,0,0,\n 0,0,E,B0,\n DF,DF,EF,EF,\n E,GF,AF,A,\n\n AF,AF,AF,AF,\n AF,AF,A,AF,\n GF,GF,GF,GF,\n GF,GF,0,0,\n \n AF0,0,AF0,0,\n AF0,0,E,B0,\n DF,DF,EF,EF,\n E,GF,AF,A,\n\n AF,AF,AF,AF,\n AF,AF,E,AF,\n B,B,B,B,\n B,B,0,0,\n \n /[\\s\\S]*half[\\s\\S]*/\n \n DF,B0,DF,EF,\n E,E,0,0,\n AF,AF,0,0,\n E,E,0,0, \n \n \n \n EF,DF,EF,E,\n GF,GF,0,0,\n B,B,0,0,\n GF,GF,0,0,\n \n DF,B0,DF,EF,\n E,0,E,EF,\n E,GF,AF,0,\n AF,A,AF,A,\n \n B,GF,EF,DF,\n B0,DF,EF,GF,\n B,B,B,B,/[\\s\\S]* END ON EITGH OR QUARTER[\\s\\S] [\\s\\S]*/\n 0,0,0,0,\n \n E0,E0,E0,E0,\n E0,E0,E0,0,\n B7,B7,B7,0,\n GF0,GF0,GF0,0,\n\n AF0,AF0,AF0,0,\n A0,A0,A0,0,\n B0,B0,B0,B0,\n B0,B0,B0,0,\n \n B0,B0,B0,B0,\n B0,B0,B0,0,\n AF0,AF0,AF0,0,\n EF,EF,EF,0,\n\n DF,DF,DF,0,\n EF,EF,EF,0,\n E,0,EF,0,\n DF,0,EF,0,\n \n E,0,0,0,\n 0,0,E,B0,\n DF,DF,EF,EF,\n E,GF,AF,A,\n \n\\};\n \n \n/[\\s\\S]* harmony [\\s\\S]*/\nconst unsigned long int CeruleanCity_middle\\[256\\] = \\{ \n \n B0,B0,B0,B0,\n DF,DF,EF,D,\n DF,DF,0,0,\n B0,B0,0,0,\n \n AF0,AF0,AF0,AF0,\n AF0,AF0,AF0,0,\n E,E,E,E,\n E,E,E,0,\n \n A0,A0,A0,0,\n AF0,0,GF0,0,\n AF0,0,A0,0,\n B0,0,DF,0,\n \n 0,0,0,0,\n 0,0,E,B0,\n DF,DF,EF,EF,\n E,GF,AF,A,\n\n DF,DF,DF,0,\n B0,B0,DF,EF,\n DF,DF,DF,0,\n B,B,B,0,\n \n 0,E0,0,E0,\n 0,0,0,0,\n AF0,AF0,AF0,AF0,\n AF0,AF0,AF0,0,\n\n B0,B0,B0,0,\n A0,0,AF0,0,\n GF0,0,AF0,0,\n A0,0,B0,0,\n \n /[\\s\\S]*half[\\s\\S]*/\n \n E0,0,GF0,0,\n AF0,0,0,0,\n E,E,0,0,\n B0,B0,0,0, \n \n GF0,0,AF0,0,\n A0,0,0,0,\n GF,GF,0,0,\n EF,EF,0,0, \n \n E0,0,0,0,\n 0,0,GF0,0,\n 0,0,0,0,\n A0,0,0,0,\n \n B0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,/[\\s\\S]* END ON EITGH OR QUARTER[\\s\\S] [\\s\\S]*/\n 0,0,0,0,\n \n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n\n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n \n E0,E0,E0,E0,\n E0,E0,E0,0,\n 0,0,0,0,\n 0,0,0,0,\n\n GF0,GF0,GF0,GF0,\n GF0,0,GF0,0,\n AF0,0,AF0,0,\n GF0,0,GF0,0,\n \n E0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n 0,0,0,0,\n \n\\};\n \n \n\n/[\\s\\S]* bass [\\s\\S]*/\nconst unsigned long int CeruleanCity_low\\[256\\] = \\{ \n \n GF7,0,A7,0,\n GF7,0,A7,0,\n B7,0,A7,0,\n AF7,0,GF7,0,\n \n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n \n GF7,0,A7,0,\n GF7,0,A7,0,\n B7,0,A7,0,\n AF7,0,GF7,0,\n \n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n \n GF7,0,A7,0,\n GF7,0,A7,0,\n B7,0,A7,0,\n AF7,0,GF7,0,\n \n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n \n GF7,0,A7,0,\n GF7,0,A7,0,\n B7,0,A7,0,\n AF7,0,GF7,0,\n \n /[\\s\\S]*half[\\s\\S]*/\n \n DF7,0,E7,0,\n DF7,0,0,0,\n AF7,0,0,0,\n E7,0,0,0,\n \n EF7,0,GF7,0,\n EF7,0,0,0,\n B7,0,0,0,\n GF7,0,0,0,\n \n \n DF7,0,0,0,\n 0,0,E7,0,\n 0,0,0,0,\n AF7,0,A7,0,\n \n B7,0,0,0,\n 0,0,0,0,\n 0,0,A7,0,\n AF7,0,GF7,0,\n \n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n E7,0,AF7,0,\n \n GF7,0,A7,0,\n GF7,0,A7,0,\n B7,0,A7,0,\n AF7,0,GF7,0,\n\n AF7,0,B7,0,\n AF7,0,B7,0,\n AF7,0,B7,0,\n AF7,0,B7,0,\n \n GF7,0,A7,0,\n GF7,0,A7,0,\n B7,0,A7,0,\n AF7,0,GF7,0\n\n\\};$"));
  }

  @After
  public void tearDown() throws Exception {
    driver.quit();
    String verificationErrorString = verificationErrors.toString();
    if (!"".equals(verificationErrorString)) {
      fail(verificationErrorString);
    }
  }

  private boolean isElementPresent(By by) {
    try {
      driver.findElement(by);
      return true;
    } catch (NoSuchElementException e) {
      return false;
    }
  }

  private boolean isAlertPresent() {
    try {
      driver.switchTo().alert();
      return true;
    } catch (NoAlertPresentException e) {
      return false;
    }
  }

  private String closeAlertAndGetItsText() {
    try {
      Alert alert = driver.switchTo().alert();
      String alertText = alert.getText();
      if (acceptNextAlert) {
        alert.accept();
      } else {
        alert.dismiss();
      }
      return alertText;
    } finally {
      acceptNextAlert = true;
    }
  }
}
