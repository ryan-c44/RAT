/* 
   When reading data files, should report on data read in.  List of customers, list of parts and builders
   all appropriately formatted. This report should go to standard out.

   Output_file is used to report on results.  Output_file should be ordered by customer and contains a clear
   report on the build plan, success or failure as necessary.

   When you start each customer, you should report to standard out the customer name, name of the order
   they are intending to be built, and the builder assigned.  Standard out whether the build succeeds or 
   fails.

   For the given customer, randomly allocate a builder who is constructing the robot.

   Determine the overall robot complexity as 20 plus the sum of the part complexities.
   If the complexity is greater than 100, it should be changed to exactly 100.

   Determine the overall robot variability as 5 + the number of parts + the variability of the builder.

   Report the customer name, project name, builder name, and the distribution parameters to the Output_file.

   The builder attempts to build the robot.  Generate a random value from a normal distribution with mean
   equal to the builders ability and standard deviation equal the the overall robot variability just 
   calculated. 
   
   if(rndValue >= overallRobotComplex) {
       build = successful
   } else {
       build = failed
   }

   If the build succeeds you can move on to the next customer.

   If the build fails, the builder can re-attempt the build twice.  For each re-attempt generate a random
   value from the same distribution as before, but for the first re-attempt add 5, for the second re-attempt
   add 10.

   After 3 fails move to next customer

   The random value and success status for each attempt should be reported to Output_file
*/