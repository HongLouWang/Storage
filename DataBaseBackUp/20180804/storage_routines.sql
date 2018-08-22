-- MySQL dump 10.13  Distrib 8.0.12, for Win64 (x86_64)
--
-- Host: 47.254.76.209    Database: storage
-- ------------------------------------------------------
-- Server version	8.0.12

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
 SET NAMES utf8 ;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Temporary view structure for view `v_logistics`
--

DROP TABLE IF EXISTS `v_logistics`;
/*!50001 DROP VIEW IF EXISTS `v_logistics`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8mb4;
/*!50001 CREATE VIEW `v_logistics` AS SELECT 
 1 AS `ID`,
 1 AS `TrackingNumber`,
 1 AS `Est_time`,
 1 AS `Value`,
 1 AS `Arrive`,
 1 AS `Arr_Date`,
 1 AS `NeedCustom`,
 1 AS `CustomCheckID`,
 1 AS `Customer_id`,
 1 AS `Customer_firstname`,
 1 AS `Customer_lastname`,
 1 AS `Customer_phone`,
 1 AS `Customer_address`,
 1 AS `Customer_email`*/;
SET character_set_client = @saved_cs_client;

--
-- Temporary view structure for view `v_logistics_freight`
--

DROP TABLE IF EXISTS `v_logistics_freight`;
/*!50001 DROP VIEW IF EXISTS `v_logistics_freight`*/;
SET @saved_cs_client     = @@character_set_client;
SET character_set_client = utf8mb4;
/*!50001 CREATE VIEW `v_logistics_freight` AS SELECT 
 1 AS `ID`,
 1 AS `Freight_TrackingNumber`,
 1 AS `Logistics_TrackingNumber`,
 1 AS `ArriveChina`,
 1 AS `ArriveUSA`,
 1 AS `ArriveChinaDate`,
 1 AS `ArriveUSADate`,
 1 AS `NeedCustom`*/;
SET character_set_client = @saved_cs_client;

--
-- Final view structure for view `v_logistics`
--

/*!50001 DROP VIEW IF EXISTS `v_logistics`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`%` SQL SECURITY DEFINER */
/*!50001 VIEW `v_logistics` (`ID`,`TrackingNumber`,`Est_time`,`Value`,`Arrive`,`Arr_Date`,`NeedCustom`,`CustomCheckID`,`Customer_id`,`Customer_firstname`,`Customer_lastname`,`Customer_phone`,`Customer_address`,`Customer_email`) AS select `logistics`.`id` AS `id`,`logistics`.`TrackingNumber` AS `TrackingNumber`,`logistics`.`Est_date` AS `Est_date`,`logistics`.`Value` AS `Value`,`logistics`.`Customer_id` AS `Customer_id`,`logistics`.`NeedCustom` AS `NeedCustom`,`logistics`.`CustomCheckId` AS `CustomCheckID`,`logistics`.`Arrive` AS `Arrive`,`logistics`.`Arr_date` AS `Arr_Date`,`customer`.`firstname` AS `Customer_firstname`,`customer`.`lastname` AS `Customer_lastname`,`customer`.`phone` AS `Customer_phone`,`customer`.`email` AS `Customer_email`,`customer`.`address` AS `Customer_address` from (`logistics` join `customer`) where (`customer`.`id` = `logistics`.`Customer_id`) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;

--
-- Final view structure for view `v_logistics_freight`
--

/*!50001 DROP VIEW IF EXISTS `v_logistics_freight`*/;
/*!50001 SET @saved_cs_client          = @@character_set_client */;
/*!50001 SET @saved_cs_results         = @@character_set_results */;
/*!50001 SET @saved_col_connection     = @@collation_connection */;
/*!50001 SET character_set_client      = utf8mb4 */;
/*!50001 SET character_set_results     = utf8mb4 */;
/*!50001 SET collation_connection      = utf8mb4_0900_ai_ci */;
/*!50001 CREATE ALGORITHM=UNDEFINED */
/*!50013 DEFINER=`root`@`%` SQL SECURITY DEFINER */
/*!50001 VIEW `v_logistics_freight` (`ID`,`Freight_TrackingNumber`,`Logistics_TrackingNumber`,`ArriveChina`,`ArriveUSA`,`ArriveChinaDate`,`ArriveUSADate`,`NeedCustom`) AS select `freight`.`id` AS `id`,`freight`.`tracking_id` AS `Freight_TrackingNumber`,`logistics_freight_check_table`.`Logistics_TrackingNumber` AS `Logistics_TrackingNumber`,`v_logistics`.`Arrive` AS `ArriveChina`,`freight`.`Arrive` AS `ArriveUSA`,`logistics`.`Arr_date` AS `ArriveChinaDate`,`freight`.`arr_date` AS `ArriveUSADate`,`freight`.`Customs` AS `NeedCustom` from (((`freight` join `logistics_freight_check_table`) join `v_logistics`) join `logistics`) where ((`freight`.`tracking_id` = `logistics_freight_check_table`.`Logistics_TrackingNumber`) and (`v_logistics`.`TrackingNumber` = `logistics_freight_check_table`.`Logistics_TrackingNumber`) and (`logistics_freight_check_table`.`Logistics_TrackingNumber` = `logistics`.`TrackingNumber`)) */;
/*!50001 SET character_set_client      = @saved_cs_client */;
/*!50001 SET character_set_results     = @saved_cs_results */;
/*!50001 SET collation_connection      = @saved_col_connection */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2018-08-04 18:36:41
