var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res, next) {
  // Basic routing
  res.render('index', {
      title: 'Express',
      rawr: 'This is a string',
      posts: [
          'rawr',
          'asd',
          'yo'
      ]
  });
});

module.exports = router;
