-- phpMyAdmin SQL Dump
-- version 3.3.9.2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 21, 2025 at 11:07 PM
-- Server version: 5.5.9
-- PHP Version: 5.3.5

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `room_raccoon_online_store`
--

-- --------------------------------------------------------

--
-- Table structure for table `categories`
--

CREATE TABLE `categories` (
  `id` int(255) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `pub` tinyint(1) NOT NULL DEFAULT '1',
  `del` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=7 ;

--
-- Dumping data for table `categories`
--

INSERT INTO `categories` VALUES(1, 'Books', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `categories` VALUES(2, 'Electronics', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `categories` VALUES(3, 'Clothing', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `categories` VALUES(4, 'Food', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `categories` VALUES(5, 'Beverages', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `categories` VALUES(6, 'Furniture', '0000-00-00 00:00:00', 1, 1);

-- --------------------------------------------------------

--
-- Table structure for table `products`
--

CREATE TABLE `products` (
  `id` int(255) NOT NULL AUTO_INCREMENT,
  `name` varchar(100) DEFAULT NULL,
  `description` tinytext NOT NULL,
  `product_picture` varchar(100) DEFAULT NULL,
  `sku` varchar(100) DEFAULT NULL,
  `barcode` varchar(20) DEFAULT NULL,
  `category` int(5) DEFAULT '0',
  `price` decimal(15,2) NOT NULL DEFAULT '0.00',
  `currency` enum('R','$') NOT NULL DEFAULT 'R',
  `date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `modified` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `pub` tinyint(1) NOT NULL DEFAULT '1',
  `del` tinyint(1) NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=latin1 AUTO_INCREMENT=15 ;

--
-- Dumping data for table `products`
--

INSERT INTO `products` VALUES(1, 'ccc', '', NULL, '', NULL, 1, 0.00, '', '2025-02-21 22:56:32', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(2, 'Testddd', '', NULL, 'erre', NULL, 1, 0.00, '', '2025-02-21 22:56:21', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(3, 'Testingx13', 'Testing desription', NULL, 'TST', NULL, 1, 299.00, '', '2025-02-21 22:56:27', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(4, 'Testing', 'Testing desription', NULL, 'TST', NULL, 3, 299.00, '', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(5, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(6, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(7, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(8, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(9, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(10, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(11, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(12, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(13, 're', 're', NULL, 're', NULL, 2, 545.00, 'R', '0000-00-00 00:00:00', '0000-00-00 00:00:00', 1, 1);
INSERT INTO `products` VALUES(14, 'Eric New', '', NULL, 'erre', NULL, 3, 299.00, 'R', '2025-02-21 22:57:00', '0000-00-00 00:00:00', 1, 1);
