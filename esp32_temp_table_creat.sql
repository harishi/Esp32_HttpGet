DROP TABLE IF EXISTS `temp_table`;
CREATE TABLE IF NOT EXISTS `temp_table` (
  `temp_id` int UNSIGNED NOT NULL AUTO_INCREMENT,
  `temp_value` float NOT NULL DEFAULT '0',
  PRIMARY KEY (`temp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_520_ci;
