/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


import junit.framework.TestCase;





/**
 * Performs Validation Test for url validations.
 *
 * @version $Revision: 1128446 $ $Date: 2011-05-27 13:29:27 -0700 (Fri, 27 May 2011) $
 */
public class UrlValidatorTest extends TestCase {

   private boolean printStatus = false;
   private boolean printIndex = false;//print index that indicates current scheme,host,port,path, query test were using.

   public UrlValidatorTest(String testName) {
      super(testName);
   }

   private static final String[] MANUAL_TEST_URLS = new String[] {
			"http://foo.com",					//benign test case
			"http://foo3.com/123/hellow0rld",	//numbers in hostname, path
			"http://foo.com/blah_bla*h/",		//'safe' characters in path
			"http://foo.com/blah_bla*h(paren)_(paren)/",		//more 'safe' characters in path
			"http://foo.com/0123$-_.+!/*|(),/",			//safe characters - fail
			"http://foo.com/\"%<>\\^`{|}",		// unsafe characters in path
			"HTTP://WWW.FOO.COM",				//all caps
			" http://foo.com",					//add space before scheme
			"hello://foo.com",					// random scheme name
			"ht!tp://foo.com",					//non alphanumeric in scheme
			"http://f oo.com",					//space within URL
			"http://foo.com ",					//trailing space
			"http://223.255.255.254",			//DNS format
			"http://foo.com/?q=testquery",		//add simple query section
			"http://foo.bar/?q=Test%20URLencoded%20stuff",	//URLencoded - fail
			// very long and complicated path (fail):			
			"http://foo:bar@w1.superman.com/very/long/path.html?p1=v1&p2=v2#more-details",
			"http://foo.com/a#b#c#",				// fragments
			"http://foo.com/a#b c#",				// space in fragements
			"ftp://ftp.rfc-editor.org/",			//ftp 
			"gopher://floodgap.com"				//gopher scheme
	};
   
   public void testManualTest()
   {
	   for(int i = 0; i < MANUAL_TEST_URLS.length; i++)
	   {
		   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
		   System.out.println(MANUAL_TEST_URLS[i]);
		   System.out.println(urlVal.isValid(MANUAL_TEST_URLS[i]));
		   System.out.println();
	   }
	     
   }
   
   
   public void testYourFirstPartition()
   {
	   
   }
   
   public void testYourSecondPartition(){
	   
   }
   
   
   public void testIsValid()
   {
	   for(int i = 0;i<10000;i++)
	   {
		   
	   }
   }
   
   public void testAnyOtherUnitTest()
   {
	   
   }
   /**
    * Create set of tests by taking the testUrlXXX arrays and
    * running through all possible permutations of their combinations.
    *
    * @param testObjects Used to create a url.
    */
   

}
